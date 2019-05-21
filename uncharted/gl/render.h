#pragma once
#include "platform/platform.h"
#include "math/vector3.h"

struct Color;

class Render
{
public:
    Render() = delete;
    explicit Render(Window* window);

public:
    void DrawPiexl(int32 x, int32 y, int32 color);

    void DrawLine(const Point& start, const Point& end, const Color& color);

    void DrawTrangle(const Point* points, int point_count);

private:
    Window* window_;
};