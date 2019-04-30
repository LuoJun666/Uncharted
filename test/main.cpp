#include "platform/platform.h"

int main()
{
    Window* window = new Window;
    const WIDECHAR* title = L"Uncharted";
    if (window->Create(1280, 800, title) != 0)
    {
        return -1;
    }

    while (!window->IsExit())
    {
        window->Run();
    }

	return 0;
}