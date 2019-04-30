#pragma once

#include <string>
#include <Windows.h>
#include "platform/platform_global_type.h"

class Window
{
public:
    Window();
    ~Window();

    int Create(int width, int height, const std::wstring& title);

    void Run();

    bool IsExit();

private:
    void DispatchWinMessage();

private:
    HWND hwnd_;
    HDC  hdc_;
    int32 width_;
    int32 height_;
    int* frame_buffer_;
};