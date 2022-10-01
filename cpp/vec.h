#pragma once

#include <iostream>
#include <type_traits>

//typedef Vec2i Vec2<int>;
//typedef Vec2f Vec2<float>;

template <typename T>
class Vec2
{
    public:
        T x;
        T y;

    public:
        Vec2(): x(0),y(0){}
        Vec2(T x_, T y_): x(x_),y(y_){}
		Vec2 operator+(Vec2 v) const
		{
			return Vec2(x+v.x, y+v.y);
		}

		Vec2 operator-(Vec2 v) const
		{
			return Vec2(x-v.x,y-v.y);
		}

		Vec2 operator*(Vec2 v) const
		{
			return Vec2(x*v.x, y*v.y);
		}

		bool operator==(Vec2 v) const
		{
			return (x==v.x && y==v.y);
		}
};


template <typename T>
class Vec3
{
	public:
		T x,y,z;

	public:
		Vec3(): x(0),y(0),z(0){}
		Vec3(T x_, T y_, T z_): x(x_), y(y_), z(z_){}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vec2<T> v)
{
    os <<"("<<v.x<<", "<<v.y<<")\n";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vec3<T> v)
{
    os <<"("<<v.x<<", "<<v.y<<", "<<v.z<<")\n";
    return os;
}
