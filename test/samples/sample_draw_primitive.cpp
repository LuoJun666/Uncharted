#include "sample_draw_primitive.h"

#include <vector>
#include <iostream>
#include "gl/render.h"
#include "gl/color.h"
#include "util/random.h"

using namespace unc;

SampleDrawPrimitive::SampleDrawPrimitive(Window* w)
    : SampleBase(w)
{
}

SampleDrawPrimitive::~SampleDrawPrimitive()
{
}

void SampleDrawPrimitive::Run()
{
    //RandomDrawLine();
    //RandomDrawTriangleWireframe();
    RandomDrawTriangle();
}

void SampleDrawPrimitive::RandomDrawLine()
{
    static int32 g_line_num = 0;
    if (g_line_num < 10000)
    {
        Point start_point(Vector3(Random::GetInt32(0, 1280), Random::GetInt32(0, 880)), Color(255, 128, 0));
        Point end_point(Vector3(Random::GetInt32(0, 1280), Random::GetInt32(0, 880)), Color(255, 128, 0));
        GetRenderer()->DrawLine(start_point, end_point);
        Sleep(1000);
        ++g_line_num;
    }
}

void SampleDrawPrimitive::RandomDrawTriangleWireframe()
{
    GetRenderer()->ClearWindow();

    const Color color = Color::ORANGE;
    std::vector<Point> point_list =
    {
        Point(Vector3(Random::GetInt32(0, 1280), Random::GetInt32(0, 880)), color),
        Point(Vector3(Random::GetInt32(0, 1280), Random::GetInt32(0, 880)), color),
        Point(Vector3(Random::GetInt32(0, 1280), Random::GetInt32(0, 880)), color),
    };
    GetRenderer()->DrawTrangleWireframe(point_list);
    Sleep(1000);
}

void SampleDrawPrimitive::RandomDrawTriangle()
{
    GetRenderer()->ClearWindow();

    const int32 k_screen_width = GetRenderer()->GetScreenWidth();
    const int32 k_screen_height = GetRenderer()->GetScreenHeight();

    for (int i = 0; i < 1; ++i)
    {
        std::vector<Point> point_list =
        {
            /*Point(Vector3(320, 220, 0), Color::RED),
            Point(Vector3(960, 220, 0), Color::GREEN),
            Point(Vector3(640, 660, 0), Color::BLUE),*/
            Point(Vector3(Random::GetInt32(0, k_screen_width), Random::GetInt32(0, k_screen_height)), Color::RED),
            Point(Vector3(Random::GetInt32(0, k_screen_width), Random::GetInt32(0, k_screen_height)), Color::GREEN),
            Point(Vector3(Random::GetInt32(0, k_screen_width), Random::GetInt32(0, k_screen_height)), Color::BLUE),
        };
        if (GetRenderer()->DrawTrangle(point_list))
        {
            /*for (auto& point : point_list)
            {
                ANSICHAR buf[128] = {0};
                snprintf(buf, 128, " x = %f, y = %f;", point.GetPosition().x, point.GetPosition().y);
                std::cout << buf << std::endl;
            }
            std::cout << std::endl;*/
            Sleep(1000);
        }
    }
}