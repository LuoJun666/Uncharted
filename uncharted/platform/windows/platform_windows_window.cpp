#include "platform_windows_window.h"

#include <tchar.h>
#include "gl/Color.h"

static bool g_exit = false;

Window::Window()
    : hwnd_(nullptr)
    , width_(0)
    , height_(0)
    , frame_buffer_(nullptr)
    , hdc_(nullptr)
    , color_(0)
{
}

Window::~Window() 
{
}

static LRESULT OnWinMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CLOSE: g_exit = true; break;
        /*case WM_KEYDOWN: screen_keys[wParam & 511] = 1; break;
        case WM_KEYUP: screen_keys[wParam & 511] = 0; break;*/
    default: return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}

static HWND screen_handle = NULL;		// 主窗口 HWND
static HDC screen_dc = NULL;			// 配套的 HDC
static HBITMAP screen_hb = NULL;		// DIB
static HBITMAP screen_ob = NULL;		// 老的 BITMAP
unsigned char* screen_fb = NULL;		// frame buffer

int screen_close(void) 
{
    if (screen_dc) 
    {
        if (screen_ob) 
        {
            SelectObject(screen_dc, screen_ob);
            screen_ob = NULL;
        }
        DeleteDC(screen_dc);
        screen_dc = NULL;
    }
    if (screen_hb) 
    {
        DeleteObject(screen_hb);
        screen_hb = NULL;
    }
    if (screen_handle) 
    {
        CloseWindow(screen_handle);
        screen_handle = NULL;
    }
    return 0;
}

int Window::Create(int width, int height, const std::wstring& title) 
{
    width_ = width;
    height_ = height;

    WNDCLASS wc = { CS_BYTEALIGNCLIENT, (WNDPROC)OnWinMessage, 0, 0, 0,
                    nullptr, nullptr, nullptr, nullptr, _T("SCREEN3.1415926") };

    //screen_close();

    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hInstance = GetModuleHandle(NULL);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    if (!RegisterClass(&wc)) return -1;

    uint32 style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;/*WS_OVERLAPPEDWINDOW;*/
    hwnd_ = CreateWindow(_T("SCREEN3.1415926"), title.c_str(), style, 0, 0, width, height, nullptr, nullptr, wc.hInstance, nullptr);
    
    /*typedef struct tagBITMAPINFOHEADER {
        DWORD      biSize;
        LONG       biWidth;
        LONG       biHeight;
        WORD       biPlanes;
        WORD       biBitCount;
        DWORD      biCompression;
        DWORD      biSizeImage;
        LONG       biXPelsPerMeter;
        LONG       biYPelsPerMeter;
        DWORD      biClrUsed;
        DWORD      biClrImportant;
    } BITMAPINFOHEADER*/

    BITMAPINFO bi =
    { 
        sizeof(BITMAPINFOHEADER), 
        width, 
        height, 
        1, 
        32, 
        BI_RGB,
        (DWORD)(width * height * 4), 
        0, 
        0, 
        0, 
        0 
    };

    HDC dc = GetDC(hwnd_);
    hdc_ = CreateCompatibleDC(dc);
    ReleaseDC(hwnd_, dc);

    int32* temp = nullptr;
    screen_hb = CreateDIBSection(hdc_, &bi, DIB_RGB_COLORS, (void**)&temp, 0, 0);
    if (screen_hb == NULL)
    {
        return -3;
    }
    frame_buffer_ = new int32 * [height_];
    for (int y = 0; y < height_; ++y)
    {
        frame_buffer_[y] = temp;
        temp += width;
    }

    screen_ob = (HBITMAP)SelectObject(hdc_, screen_hb);
    ShowWindow(hwnd_, SW_NORMAL);
    DispatchWinMessage();

    SetBackgroundColor(unc::Color(255, 255, 255).GetInt32());

    return 0;
}

void Window::Update() 
{
    HDC hDC = GetDC(hwnd_);
    BitBlt(hDC, 0, 0, width_, height_, hdc_, 0, 0, SRCCOPY);
    ReleaseDC(hwnd_, hDC);
    DispatchWinMessage();
}

bool Window::IsExit()
{
    return g_exit;
}

void Window::SetPixel(int32 x, int32 y, int32 color) 
{
    if (y < 0 || x < 0) return;

    x = std::min<int32>(x, width_ - 1);
    y = std::min<int32>(y, height_ - 1);
    frame_buffer_[y][x] = color;
}

void Window::DispatchWinMessage() 
{
    MSG msg;
    while (1) 
    {
        if (!PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) break;
        if (!GetMessage(&msg, NULL, 0, 0)) break;
        DispatchMessage(&msg);
    }
}

void Window::SetBackgroundColor(int32 color)
{
    for (int32 y = 0; y < height_; ++y)
    {
        for (int32 x = 0; x < width_; ++x)
        {
            frame_buffer_[y][x] = color;
        }
    }
    color_ = color;
}