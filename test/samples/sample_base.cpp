#include "sample_base.h"

#include "gl/render.h"

SampleBase::SampleBase(Window* w)
{
    renderer_ = new Render(w);
}

SampleBase::~SampleBase()
{
    delete renderer_;
}