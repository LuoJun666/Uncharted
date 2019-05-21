#include "render.h"
#include <utility>
#include <iostream>
#include "gl/color.h"

Render::Render(Window* window)
    : window_(window)
{
}

void Render::DrawLine(const Point& start, const Point& end, const Color& color) 
{
    int32 x0 = (int32)start.x;
    int32 y0 = (int32)start.y;
    int32 x1 = (int32)end.x;
    int32 y1 = (int32)end.y;

    // ���б�ʴ���1�����ô�б��ֱ�߶�ֱ��y=x�ķ�����һ��Сб��ֱ�ߵ���ʵ����������������н��� x �� y
    bool steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep)
    {
        std::swap<int32>(x0, y0);
        std::swap<int32>(x1, y1);
    }
    // ����������յ㣬���������յ�����
    if (x0 > x1)
    {
        std::swap<int32>(x0, x1);
        std::swap<int32>(y0, y1);
    }

    int32 delta_x = x1 - x0;
    int32 delta_y = abs(y1 - y0);
    int32 error = delta_x / 2;
    int32 y = y0;
    int32 y_step = y0 < y1 ? 1 : -1;
    
    for (int32 x = x0; x <= x1; ++x)
    {
        if (steep)
        {
            window_->SetPixel(y, x, color.Get());
        }
        else
        {
            window_->SetPixel(x, y, color.Get());
        }
        error = error - delta_y;
        if (error < 0)
        {
            y = y + y_step;
            error = error + delta_x;
        }
        //std::cout << "x:" << x << ", y: " << y << std::endl;
    }
}