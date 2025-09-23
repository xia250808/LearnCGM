#pragma once
#include <iostream>
using namespace std;


enum class RotationOrder { XYZ, YZX, ZXY, XZY, YXZ, ZYX };
std::ostream& operator<<(std::ostream& os, RotationOrder order);

struct Eul {
	float pitch;
	float yaw;
	float roll;
	RotationOrder order;
	const float epsilon = 1e-6f;
	void print();
	Eul(float p = 0, float y = 0, float r = 0, RotationOrder o = RotationOrder::YXZ): pitch(p), yaw(y), roll(r),order(o) {}
	float normalize_angle(float angle);
};