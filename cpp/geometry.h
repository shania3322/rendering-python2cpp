#pragma once

#include "vec.h"


class Line {
    public:
        Vec2<int> start;
        Vec2<int> end;
    public:
        Line(Vec2<int> a,Vec2<int> b,unsigned int *pixels, int width);
        void draw(unsigned int *pixel, int width);
};


