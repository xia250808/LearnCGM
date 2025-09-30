#pragma once
#include <iostream>
#include "mat/mat3.h"
#include "quater/quater.h"
using namespace std;


enum class RotationOrder { XYZ, YZX, ZXY, XZY, YXZ, ZYX };
std::ostream& operator<<(std::ostream& os, RotationOrder order);
class Mat3;
struct Quater;
struct Eul {
	float pitch;
	float yaw;
	float roll;
	RotationOrder order;
	const float epsilon = 1e-6f;
	void print();
	Eul(float y = 0,float x = 0, float z = 0, RotationOrder o = RotationOrder::YXZ): yaw(y), pitch(x), roll(z),order(o) {}
	float normalize_angle(float angle);
	Mat3 transToMat3();
	Quater transToQuater();
	bool operator==(const Eul& other);
};
