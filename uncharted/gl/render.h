#pragma once

#include <vector>
#include "gl/Point.h"
#include "platform/platform.h"

//class Window;

class Render
{
public:
    Render() = delete;
    explicit Render(Window* window);

public:
    void DrawLine(const unc::Point& start, const unc::Point& end);

    void DrawTrangleWireframe(const std::vector<unc::Point>& point_list);

    bool DrawTrangle(const std::vector<unc::Point>& point_list);

    void ClearWindow();

    int32 GetScreenWidth() const;

    int32 GetScreenHeight() const;

private:
    void SortPointToClockwise(std::vector<unc::Point>& point_list);

private:
    Window* window_;
};