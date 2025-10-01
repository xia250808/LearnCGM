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
	cout << "Rotaion order: "<< endl;
	cout << "yaw = " << this->yaw << endl;
	cout << "pitch = " << this->pitch << endl;
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
// M=R*P*Y
Mat3 Eul::transToMat3() {
	float p = normalize_angle(pitch);
	float y = normalize_angle(yaw);
	float r = normalize_angle(roll);
	float cp = cosf(p), sp = sinf(p);
	float cy = cosf(y), sy = sinf(y);
	float cr = cosf(r), sr = sinf(r);

	Mat3 retMat3 = Mat3();

	retMat3.mat[0][0] = cy * cr + sy * sp * sr;
	retMat3.mat[0][1] = sr * cp;
	retMat3.mat[0][2] = -sy * cr + cy * sp * sr;
	retMat3.mat[1][0] = -cy * sr + sy * sp * cr;
	retMat3.mat[1][1] = cr * cp;
	retMat3.mat[1][2] = sr * sy + cy * sp * cr;
	retMat3.mat[2][0] = sy * cp;
	retMat3.mat[2][1] = -sp;
	retMat3.mat[2][2] = cy * cp;

	return retMat3;

}

Quater Eul::transToQuater()
{	
	float p = normalize_angle(pitch);
	float y = normalize_angle(yaw);
	float r = normalize_angle(roll);
	float cy2 = cosf(y / 2.0), sy2 = sinf(y / 2.0);
	float cp2 = cosf(p / 2.0), sp2 = sinf(p / 2.0);
	float cr2 = cosf(r / 2.0), sr2 = sinf(r / 2.0);
	Quater retQuater = Quater();
	retQuater.w = cy2 * cp2 * cr2 + sy2 * sp2 * sr2;
	retQuater.x = cy2 * sp2 * cr2 + sy2 * cp2 * sr2;
	retQuater.y = sy2 * cp2 * cr2 - cy2 * sp2 * sr2;
	retQuater.z = cy2 * cp2 * sr2 - sy2 * sp2 * cr2;

	return retQuater;
}

bool Eul::operator==(const Eul& other)
{
	return fabs(pitch - other.pitch) < 1e-6f && fabs(yaw - other.yaw) < 1e-6f && fabs(roll - other.roll) < 1e-6f;
}
