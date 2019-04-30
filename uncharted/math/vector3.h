#pragma once

#include <cmath>
#include "platform/platform_global_type.h"

struct Vector3
{
public:
    float x;
    float y;
    float z;

public:
    Vector3() = delete;
    
    explicit Vector3(float v)
    {
        x = v;
        y = v;
        z = v;
    }

    Vector3(float vx, float vy, float vz)
    {
        x = vx;
        y = vy;
        z = vz;
    }

    Vector3(int32 vx, int32 vy, int32 vz)
    {
        x = static_cast<float>(vx);
        y = static_cast<float>(vy);
        z = static_cast<float>(vz);
    }

    Vector3 operator +(float v) const
    {
        return Vector3(x + v, y + v, z + v);
    }

    Vector3 operator -(float v) const
    {
        return Vector3(x - v, y - v, z - v);
    }

    Vector3 operator *(float v) const
    {
        return Vector3(x * v, y * v, z * v);
    }

    Vector3 operator /(float v) const
    {
        float s = 1 / v;
        return Vector3(x * s, y * s, z * s);
    }

    Vector3 operator +(const Vector3& v) const
    {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    Vector3 operator -(const Vector3& v) const
    {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    /**
     *  向量点乘
     */
    float DotProduct(const Vector3& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    /**
     *  向量叉乘
     */
    Vector3 CrossProduct(const Vector3& v) const
    {
        return Vector3
        (
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        );
    }

    /**
     *  向量大小
     */
    float Size() const
    {
        return std::sqrt(x * x + x * x + z * z);
    }
};

typedef Vector3 Point;