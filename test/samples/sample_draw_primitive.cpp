#include "sample_draw_primitive.h"

#include <vector>
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
        Point start_point(Vector3(Random::Get(0, 1280), Random::Get(0, 880)), Color(255, 128, 0));
        Point end_point(Vector3(Random::Get(0, 1280), Random::Get(0, 880)), Color(255, 128, 0));
        GetRenderer()->DrawLine(start_point, end_point);
        ++g_line_num;
    }
}

void SampleDrawPrimitive::RandomDrawTriangleWireframe()
{
    std::vector<Point> point_list =
    {
        Point(Vector3(Random::Get(0, 1280), Random::Get(0, 880)), Color(255, 128, 0)),
        Point(Vector3(Random::Get(0, 1280), Random::Get(0, 880)), Color(255, 128, 0)),
        Point(Vector3(Random::Get(0, 1280), Random::Get(0, 880)), Color(255, 128, 0)),
    };
    GetRenderer()->DrawTrangleWireframe(point_list);
    Sleep(1000);
}

void SampleDrawPrimitive::RandomDrawTriangle()
{
    GetRenderer()->ClearWindow();

    const int32 k_screen_width = GetRenderer()->GetScreenWidth();
    const int32 k_screen_height = GetRenderer()->GetScreenHeight();
    std::vector<Point> point_list =
    {
        Point(Vector3(Random::Get(0, k_screen_width), Random::Get(0, k_screen_height)), Color::RED),
        Point(Vector3(Random::Get(0, k_screen_width), Random::Get(0, k_screen_height)), Color::GREEN),
        Point(Vector3(Random::Get(0, k_screen_width), Random::Get(0, k_screen_height)), Color::BLUE),
    };
    GetRenderer()->DrawTrangle(point_list);
}