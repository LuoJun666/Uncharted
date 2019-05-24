#include "render.h"
#include <iostream>
#include <algorithm>

#include "gl/color.h"

using namespace unc;

Render::Render(Window* window)
    : window_(window)
{
}

void Render::DrawLine(const Point& start, const Point& end) 
{
    int32 x0 = (int32)start.GetPosition().x;
    int32 y0 = (int32)start.GetPosition().y;
    int32 x1 = (int32)end.GetPosition().x;
    int32 y1 = (int32)end.GetPosition().y;
    const int32 color = start.GetColor().GetInt32();

    // ���б�ʴ���1�����ô�б��ֱ�߶�ֱ��y=x�ķ�����һ��Сб��ֱ�ߵ���ʵ����������������н��� x �� y
    bool steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep)
    {
        std::swap(x0, y0);
        std::swap(x1, y1);
    }
    // ����������յ㣬���������յ�����
    if (x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
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
            window_->SetPixel(y, x, color);
        }
        else
        {
            window_->SetPixel(x, y, color);
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

void Render::DrawTrangleWireframe(const std::vector<Point>& point_list)
{
    if (point_list.size() != 3) return;

    DrawLine(point_list[0], point_list[1]);
    DrawLine(point_list[0], point_list[2]);
    DrawLine(point_list[1], point_list[2]);
}

void Render::DrawTrangle(const std::vector<unc::Point>& point_list)
{
    // ��������������
    const Point& v0 = point_list[0];
    const Point& v1 = point_list[1];
    const Point& v2 = point_list[2];

    // ���������ΰ�Χ����
    int32 min_x = (int32)std::min<float>(std::min<float>(v0.GetPosition().x, v1.GetPosition().x), v2.GetPosition().x);
    int32 min_y = (int32)std::min<float>(std::min<float>(v0.GetPosition().y, v1.GetPosition().y), v2.GetPosition().y);
    int32 max_x = (int32)std::max<float>(std::max<float>(v0.GetPosition().x, v1.GetPosition().x), v2.GetPosition().x);
    int32 max_y = (int32)std::max<float>(std::max<float>(v0.GetPosition().y, v1.GetPosition().y), v2.GetPosition().y);

    auto CaluateVecCrossProduct = [](const Point& v, const Point& q, const Point& p) -> float
    {
        Vector3 vq;
        vq.x = q.GetPosition().x - v.GetPosition().x;
        vq.y = q.GetPosition().y - v.GetPosition().y;
        vq.z = 0;

        Vector3 vp;
        vp.x = p.GetPosition().x - v.GetPosition().x;
        vp.y = p.GetPosition().y - v.GetPosition().y;
        vp.z = 0;

        Vector3 ret = vq.CrossProduct(vp);
        return ret.z;
    };

    // ������������� = ����v0�Ͷ���v1,v2���ɵ������Ĳ�� / 2
    float area = CaluateVecCrossProduct(v0, v1, v2);

    // ������Χ�����еĵ�
    for (int32 x = min_x; x <= max_x; ++x)
    {
        for (int32 y = min_y; y <= max_y; ++y)
        {
            Point p(Vector3(x, y, 0));

            // �����Ƿ�����������
            float exact = 1E-8f;
            float e0 = CaluateVecCrossProduct(v0, v1, p) / area;
            float e1 = CaluateVecCrossProduct(v1, v2, p) / area;
            float e2 = CaluateVecCrossProduct(v2, v0, p) / area;
            
            // ��ɫ��ֵ
            if ((e0 >= 0 && e1 >= 0 && e2 >=0)
                || (e0 <= 0 && e1 <= 0 && e2 <= 0))
            {
                Color color;
                color.r = (uint8)(e0 * v0.GetColor().r + e1 * v1.GetColor().r + e2 * v2.GetColor().r);
                color.g = (uint8)(e0 * v0.GetColor().g + e1 * v1.GetColor().g + e2 * v2.GetColor().g);
                color.b = (uint8)(e0 * v0.GetColor().b + e1 * v1.GetColor().b + e2 * v2.GetColor().b);

                window_->SetPixel(x, y, color.GetInt32());
            }
        }
    }
}

void Render::ClearWindow()
{
    window_->Clear();
}

int32 Render::GetScreenWidth() const
{
    return window_->GetWidth();
}

int32 Render::GetScreenHeight() const
{
    return window_->GetHeight();
}