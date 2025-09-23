#include "eul/eul.h"
#include <iostream>
#include <numbers>

using namespace std;

std::ostream& operator<<(std::ostream& os, RotationOrder order) {
	switch (order) {
	case RotationOrder::XYZ: os << "XYZ"; break;
	case RotationOrder::YZX: os << "YZX"; break;
	case RotationOrder::ZXY: os << "ZXY"; break;
	case RotationOrder::XZY: os << "XZY"; break;
	case RotationOrder::YXZ: os << "YXZ"; break;
	case RotationOrder::ZYX: os << "ZYX"; break;
	default: os << "Unknown";
	}
	return os;
}
void Eul::print() {
	cout << "epsilon = " << this->epsilon << endl;
	cout << "pitch = " << this->pitch << endl;
	cout << "yaw = " << this->yaw << endl;
	cout << "roll = " << this->roll << endl;
	cout << "rotation order = " << this->order << endl;
}

float Eul::normalize_angle(float angle) {
	double pi = numbers::pi;
	angle = std::fmod(angle + pi, 2 * pi) - pi;
	if (angle > pi - this->epsilon) angle -= 2 * pi;
	if (angle < -pi + this->epsilon) angle += 2 * pi;

	return angle;
}