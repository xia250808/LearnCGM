#pragma once
#include <corecrt_math.h>
#include <cmath>
#include<array>
#include "mat/mat3.h"

class Mat3;

struct Vec3
{
	float x = 0;
	float y = 0;
	float z = 0;
	Vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {};
	void print()const;

	Vec3 operator+(const Vec3& other) const;
	array<float, 3> toArray()const;
    Vec3 operator*(const float k);

    float operator*(const Vec3& other)const;

    Vec3 cross(const Vec3& other) const;

    Vec3 operator*(const Mat3& M3x3) const;

    float length() const;

    Vec3 normalized()const;
};