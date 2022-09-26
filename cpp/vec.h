#pragma once

#include <iostream>
#include <type_traits>


//typedef Vec2i Vec2<int>;
//typedef Vec2f Vec2<float>;


template <typename T>
class Vec2
{
    //TODO: allow int and float types , may use variant and template
    public:
        T x;
        T y;

    public:
        Vec2(): x(0),y(0){}
        Vec2(T x_, T y_): x(x_),y(y_){}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vec2<T> v)
{
    os <<"("<<v.x<<", "<<v.y<<")";
    return os;
}

