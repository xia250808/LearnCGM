#pragma once
#include "mat/mat3.h"
#include "eul/eul.h"
#include <array>

class Mat3;
struct Eul;

struct Quater
{
	float w;
	float x;
	float y;
	float z;
	Quater();
	Quater(std::array<float, 4> initArray);
	Quater inverse();
	bool isUnit();
	Mat3 transToMat3();
	Eul transToEul();
};