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
    Vector3()
        : x(0.0f), y(0.0f), z(0.0f)
    {
    }
    
    explicit Vector3(float v)
        : x(v), y(v), z(v)
    {
    }

    Vector3(float vx, float vy, float vz)
        : x(vx), y(vy), z(vz)
    {
    }

    Vector3(int32 vx, int32 vy, int32 vz)
    {
        x = static_cast<float>(vx);
        y = static_cast<float>(vy);
        z = static_cast<float>(vz);
    }

    Vector3(int32 vx, int32 vy)
    {
        x = static_cast<float>(vx);
        y = static_cast<float>(vy);
        z = 0;
    }

    Vector3(const Vector3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    Vector3& operator =(const Vector3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    void Set(int32 vx, int32 vy, int32 vz)
    {
        x = static_cast<float>(vx);
        y = static_cast<float>(vy);
        z = static_cast<float>(vz);
    }

    void Set(float vx, float vy, float vz)
    {
        x = vx;
        y = vy;
        z = vz;
    }

    /**
     *  ����������˷�
     */
    Vector3 operator *(float v) const
    {
        return Vector3(x * v, y * v, z * v);
    }

    /**
    *  �������������
    */
    Vector3 operator /(float v) const
    {
        const float s = 1 / v;
        return Vector3(x * s, y * s, z * s);
    }

    /**
     *  �����ӷ�
     */
    Vector3 operator +(const Vector3& other) const
    {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    /**
     *  ���������� ����Ϊ�Ӹ�����
     */
    Vector3 operator -(const Vector3& other) const
    {
        return Vector3(*this + other.Negate());
    }

    /**
     *  ����ȡ��
     */
    Vector3 Negate() const
    {
        return Vector3(-x, -y, -z);
    }

    /**
     *  �������
     */
    float DotProduct(const Vector3& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    /**
     *  �������
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
     *  ������С
     */
    float Size() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }
};