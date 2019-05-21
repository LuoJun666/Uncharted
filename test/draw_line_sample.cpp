#include "draw_line_sample.h"
#include "gl/render.h"
#include "gl/color.h"

DrawLineSample::DrawLineSample(Window* w)
{
    renderer_ = new Render(w);
}

DrawLineSample::~DrawLineSample()
{
}

void DrawLineSample::Run()
{
    Point start_point(0, 440, 0);
    Point end_point(1280, 440, 0);
    renderer_->DrawLine(start_point, end_point, Color(255, 128, 0));
}