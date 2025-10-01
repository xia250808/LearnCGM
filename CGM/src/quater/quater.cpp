#include <array>
#include "quater/quater.h"
#include <numbers>

Quater::Quater()
{
	w = 1;
	x = 0;
	y = 0;
	z = 0;
}

Quater::Quater(array<float, 4> initArray)
{
	w = initArray[0];
	x = initArray[1];
	y = initArray[2];
	z = initArray[3];
}


Quater Quater::inverse()
{
	return Quater({w,-x,-y,-z});
}

bool Quater::isUnit()
{
	return fabs(w * w + x * x + y * y + z * z - 1) < 1.0e-6;
}

Mat3 Quater::transToMat3()
{
	Mat3 retMat3 = Mat3();
	retMat3.mat[0][0] = 1 - 2 * y * y - 2 * z * z;
	retMat3.mat[0][1] = 2 * x * y + 2 * w * z;
	retMat3.mat[0][2] = 2 * x * z - 2 * w * y;

	retMat3.mat[1][0] = 2 * x * y - 2 * w * z;
	retMat3.mat[1][1] = 1 - 2 * x * x - 2 * z * z;
	retMat3.mat[1][2] = 2 * y * z + 2 * w * x;

	retMat3.mat[2][0] = 2 * x * z + 2 * w * y;
	retMat3.mat[2][1] = 2 * y * z - 2 * w * x;
	retMat3.mat[2][2] = 1 - 2 * x * x - 2 * y * y;

	return retMat3;
}

Eul Quater::transToEul() {

	float yaw, pitch, roll;
	float sp = -2.0f * (y * z - w * x);
	if (sp>0.9999f)
	{
		pitch = numbers::pi / 2.0;
		roll = 0.0f;
		yaw = atan2(w * y - x * z, 0.5f - y * y - z * z);
	}
	else
	{
		pitch = asin(sp);
		roll = atan2(x * y + w * z, 0.5 - x * x - z * z);
		yaw = atan2(x * z + w * y, 0.5f - x * x - y * y);
	}
	return Eul(yaw, pitch, roll);
}