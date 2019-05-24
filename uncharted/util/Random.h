#pragma once

#include <random>
#include "platform/platform_global_type.h"

namespace unc
{

class Random
{
public:
    //template <typename T>
    static int32 Get(int32 min, int32 max)
    {
        /*std::default_random_engine engine(std::random_device());
        std::uniform_int_distribution<int32> uniform_dist(min, max);
        return uniform_dist(engine);*/
        return std::rand() % max;
    }
};

};