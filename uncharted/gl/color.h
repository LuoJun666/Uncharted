#pragma once

#include <algorithm>

struct Color
{
public:
    uint8 r;
    uint8 g;
    uint8 b;

    Color() = delete;

    Color(uint8 vr, uint8 vg, uint8 vb)
        : r(vr), g(vg), b(vb)
    {
    }

    int Get() const
    {
        int color = (((int)r << 16) | ((int)g << 8) | ((int)b));
        return color;
    }
};