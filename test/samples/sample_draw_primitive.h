#pragma once

#include "sample_base.h"

class SampleDrawPrimitive : public SampleBase
{
public:
    SampleDrawPrimitive() = delete;
    
    explicit SampleDrawPrimitive(Window* window);
    
    ~SampleDrawPrimitive();

public:
    void Run() override;

private:
    void RandomDrawLine();

    void RandomDrawTriangleWireframe();

    void RandomDrawTriangle();
};