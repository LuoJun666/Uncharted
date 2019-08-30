#include <iostream>

#include "platform/platform.h"
#include "gl/render.h"
#include "samples/sample_draw_primitive.h"

int main()
{
    Window* window = new Window;
    const WIDECHAR* title = L"Uncharted Samples";
    if (window->Create(1280, 880, title) != 0)
    {
        return -1;
    }

    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    LARGE_INTEGER confg_interval;
    confg_interval.QuadPart = (int64)(1.0f / 60 * freq.QuadPart);

    LARGE_INTEGER last;
    LARGE_INTEGER now;
    QueryPerformanceCounter(&last);

    int64 frame_interval = 0LL;
    int64 wait_ms = 0L;

    SampleDrawPrimitive* sample = new SampleDrawPrimitive(window);
    while (!window->IsExit())
    {
        QueryPerformanceCounter(&now);
        frame_interval = now.QuadPart - last.QuadPart;
        if (frame_interval >= confg_interval.QuadPart)
        {
            last.QuadPart = now.QuadPart;

            sample->Run();
            window->Update();
            //Sleep(1000 * 20);
        }
        else
        {
            wait_ms = (confg_interval.QuadPart - frame_interval) * 1000LL / freq.QuadPart - 1L;
            if (wait_ms > 1L)
            {
                Sleep((DWORD)wait_ms);
            }
        }
    }

	return 0;
}