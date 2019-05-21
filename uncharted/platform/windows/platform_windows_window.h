#pragma once

#include <string>
#include <Windows.h>
#include "platform/platform_global_type.h"

class Window
{
public:
    Window();
    ~Window();

    int Create(int32 width, int32 height, const std::wstring& title);

    void Update();

    bool IsExit();

    void SetPixel(int32 x, int32 y, int32 color);

    void SetBackgroundColor(int32 color);

private:
    void DispatchWinMessage();

private:
    HWND hwnd_;
    HDC  hdc_;
    int32 width_;
    int32 height_;
    int32** frame_buffer_;
};