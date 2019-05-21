#include "platform/platform.h"
#include "gl/render.h"
#include "draw_line_sample.h"

int main()
{
    Window* window = new Window;
    const WIDECHAR* title = L"Uncharted Samples";
    if (window->Create(1280, 880, title) != 0)
    {
        return -1;
    }

    DrawLineSample draw_line_sample(window);
    draw_line_sample.Run();
    while (!window->IsExit())
    {
        window->Update();
        Sleep(100);
    }

	return 0;
}