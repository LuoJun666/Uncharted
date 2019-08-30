#pragma once

#include <algorithm>
#include "platform/platform_global_type.h"

namespace unc
{

struct Color
{
public:
    uint8 r;
    uint8 g;
    uint8 b;

    static const Color WHITE;
    static const Color YELLOW;
    static const Color BLUE;
    static const Color GREEN;
    static const Color RED;
    static const Color MAGENTA;
    static const Color BLACK;
    static const Color ORANGE;
    static const Color GRAY;

    Color() : r(0), g(0), b(0)
    {
    }

    Color(uint8 vr, uint8 vg, uint8 vb)
        : r(vr), g(vg), b(vb)
    {
    }

    Color(const Color& other)
        : r(other.r), g(other.g), b(other.b)
    {
    }

    Color& operator =(const Color& other)
    {
        r = other.r;
        g = other.g;
        b = other.b;
        return *this;
    }

    void Set(uint8 vr, uint8 vg, uint8 vb)
    {
        r = vr;
        g = vg;
        b = vb;
    }

    int32 GetInt32() const
    {
        int32 color = (((int)r << 16) | ((int)g << 8) | ((int)b));
        return color;
    }
};

};