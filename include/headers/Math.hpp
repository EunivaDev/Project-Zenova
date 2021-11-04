#pragma once

#include <iostream>

using namespace std;

struct Vector2f
{
    float x, y;

    Vector2f() : x(0.0), y(0.0)
    {}

    Vector2f(float p_x, float p_y) : x(p_x), y(p_y)
    {}

    void print()
    {
        cout << x << ", " << y << endl;
    }
};