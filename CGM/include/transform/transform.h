#pragma once
#include "mat/mat3.h"
#include "mat/mat4.h"
#include "vec/vec3.h"

class Transform {
private:

public:
	static Mat3 CreateRotationMat3AroundAxis(const Vec3& axis, float angleRadians);
	static Mat3 CreateScalingMat3longAxis(const Vec3& axis, float k);
	// 这里的axis是该平面的法线
	static Mat3 CreateReflectionMat3OverPlane(const Vec3& axis);
	
	static Mat3 CreateOrthographicProjectionMat3AlongDirection(const Vec3& axis);
	// 原本3x3变换矩阵都基于原点，这个变换可以把3x3矩阵提升为绕过任意点的轴
	static Mat4 Create4x4AffineMatrixFrom3x3(const Mat3& M3x3, const Vec3& translation = Vec3(0, 0, 0));
	static Mat4 CreateTranslationMat4(const Vec3& translation = Vec3(0, 0, 0));
};