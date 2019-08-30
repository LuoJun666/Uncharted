#pragma once

#include <random>
#include "platform/platform_global_type.h"

namespace unc
{

class Random
{
public:
    static int32 GetInt32(int32 min, int32 max)
    {
        if (min > max)
        {
            std::swap(min, max);
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int32> distributor(min, max);
        return distributor(gen);
    }
    
    static float GetFloat(float min, float max)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> distributor(min, max);
        return distributor(gen);
    }
};

};