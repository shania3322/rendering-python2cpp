#include "geometry.h"

#define RED 0xFF000000

Line::Line(Vec2<int> a, Vec2<int> b){
    start.x = a.x;
    start.y = a.y;
    end.x = b.x;
    end.y = b.y;
}

void Line::draw(unsigned int *pixels, int width){
	for (float t=0.0f; t<1.0f; t+=0.01f)
	{
		int x = start.x+(end.x-start.x)*t;
		int y = start.y+(end.y-start.y)*t;
		pixels[x*width+y] = RED;
	}
}
