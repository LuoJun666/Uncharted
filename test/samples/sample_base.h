#pragma once

class Render;
class Window;

class SampleBase
{
public:
    SampleBase() = delete;
    
    explicit SampleBase(Window* window);
    
    virtual ~SampleBase();

    virtual void Run() = 0;

protected:
    Render* GetRenderer() 
    {
        return renderer_;
    }

private:
    Render* renderer_;
};