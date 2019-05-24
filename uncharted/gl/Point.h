#pragma once

#include "color.h"
#include "math/vector3.h"

namespace unc
{

class Point
{
public:
    Point()
    {
    }

    Point(const Color& c) 
        : color_(c)
    {
    }

    Point(const Vector3& v3)
        : position_(v3)
    {
    }

    Point(const Vector3& v3, const Color& c)
        : color_(c), position_(v3)
    {
    }

    Point(const Color& c, const Vector3& v3)
        : color_(c), position_(v3)
    {
    }

    void SetColor(const Color& c)
    {
        color_ = c;
    }

    const Color& GetColor() const
    {
        return color_;
    }

    void SetPosition(const Vector3& v3)
    {
        position_ = v3;
    }

    const Vector3& GetPosition() const
    {
        return position_;
    }

private:
    Color color_;
    Vector3 position_;
};

};