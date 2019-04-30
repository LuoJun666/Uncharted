#pragma once
#include "platform/platform_global_type.h"
#include "math/vector3.h"

class Render
{
public:
    static void DrawTrangle(const Point* points, int point_count);

private:
    static void DrawPiexl(int32 x, int32 y, int32 color);

    static void DrawLine();
};