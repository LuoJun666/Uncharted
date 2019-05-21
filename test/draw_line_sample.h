#pragma once

class Render;
class Window;

class DrawLineSample
{
public:
    DrawLineSample() = delete;
    explicit DrawLineSample(Window* window);
    ~DrawLineSample();

    void Run();

private:
    Render* renderer_;
};