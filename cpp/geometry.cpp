#include <algorithm>
#include <cmath>
#include "geometry.h"

#define RED 0xFF000000

Line::Line(Vec2<int> a, Vec2<int> b, unsigned int *pixels, int width){
    start.x = a.x;
    start.y = a.y;
    end.x = b.x;
    end.y = b.y;
	this->draw(pixels, width);
}

void Line::draw(unsigned int *pixels, int width){
	bool transpose=false;
	if(abs(start.x-end.x)<abs(start.y-end.y))
	{
		std::swap(start.x, start.y);
		std::swap(end.x, end.y);
		transpose=true;
	}
	//Swap start and end if x is not increasing
	if (end.x-start.x<0)
	{
		std::swap(start.x, end.x);
		std::swap(start.y, end.y);
	}

	int dx = end.x-start.x;
	int dy = end.y-start.y;
	int delta_p = abs(dy)*2; // delta_p <- delta*dx*2
	int acc_error_double = 0;
	int y = start.y;
	for (int x=start.x; x<= end.x; x++)
	{
		if(transpose){
			pixels[x*width+y] = RED;
		}
		else{
			pixels[y*width+x] = RED;
		}
		// After transpose and swap, now we deal with lines from -pi/4 to pi/4
		// such that when moving 1 step along x, the distance moving along y is
		// smaller or equal to 1.
		acc_error_double += delta_p; //acc_error_double + dx*delta*2
		if (acc_error_double > dx) {
			y = end.y>start.y?(y+1):(y-1);
			acc_error_double-=dx*2; // acc_error_double - dx*2
		}
	}
}


