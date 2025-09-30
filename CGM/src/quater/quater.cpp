#include <array>
#include "quater/quater.h"

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
