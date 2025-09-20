#pragma once
#include "mat/mat3.h"
#include "vec/vec3.h"
#include "transform/transform.h"

Mat3 Transform::CreateRotationMat3AroundAxis(const Vec3& axis, float angleRadians) {
    Vec3 axisNormalized = axis.normalized();
    float a = cos(angleRadians);
    float b = sin(angleRadians);
    float oneSub_a = 1 - cos(angleRadians);

    Mat3 rotationMat3;
    rotationMat3.mat[0][0] = axisNormalized.x * axisNormalized.x * oneSub_a + a;
    rotationMat3.mat[0][1] = axisNormalized.x * axisNormalized.y * oneSub_a + axisNormalized.z * b;
    rotationMat3.mat[0][2] = axisNormalized.x * axisNormalized.z * oneSub_a - axisNormalized.y * b;

    rotationMat3.mat[1][0] = axisNormalized.x * axisNormalized.y * oneSub_a - axisNormalized.z * b;
    rotationMat3.mat[1][1] = axisNormalized.y * axisNormalized.y * oneSub_a + a;
    rotationMat3.mat[1][2] = axisNormalized.y * axisNormalized.z * oneSub_a + axisNormalized.x * b;

    rotationMat3.mat[2][0] = axisNormalized.x * axisNormalized.z * oneSub_a + axisNormalized.y * b;
    rotationMat3.mat[2][1] = axisNormalized.y * axisNormalized.z * oneSub_a - axisNormalized.x * b;
    rotationMat3.mat[2][2] = axisNormalized.z * axisNormalized.z * oneSub_a + a;

    return rotationMat3;
}

Mat3 Transform::CreateScalingMat3longAxis(const Vec3& axis, float scaleFactor) {
    Vec3 axisNormalized = axis.normalized();
    //数学原理
    /*沿任意单位向量 k = (kx, ky, kz)的缩放矩阵 S可通过以下公式推导：
    S = I + (s−1)⋅(k⊗k)
    其中：
    I是 3x3 单位矩阵（对角线为 1，其余为 0）；
    s是缩放因子（如 2.0f表示沿轴方向放大1倍）；
    k⊗k是 k的外积（张量积），结果为一个 3x3 矩阵，每个元素为 ki⋅kj(i为行，j为列)。*/
    Mat3 scalingMatrix;
    scalingMatrix.mat[0][0] = 1 + (scaleFactor - 1) * axisNormalized.x * axisNormalized.x;
    scalingMatrix.mat[0][1] = (scaleFactor - 1) * axisNormalized.x * axisNormalized.y;
    scalingMatrix.mat[0][2] = (scaleFactor - 1) * axisNormalized.x * axisNormalized.z;

    scalingMatrix.mat[1][0] = (scaleFactor - 1) * axisNormalized.x * axisNormalized.y;
    scalingMatrix.mat[1][1] = 1 + (scaleFactor - 1) * axisNormalized.y * axisNormalized.y;
    scalingMatrix.mat[1][2] = (scaleFactor - 1) * axisNormalized.y * axisNormalized.z;

    scalingMatrix.mat[2][0] = (scaleFactor - 1) * axisNormalized.x * axisNormalized.z;
    scalingMatrix.mat[2][1] = (scaleFactor - 1) * axisNormalized.y * axisNormalized.z;
    scalingMatrix.mat[2][2] = 1 + (scaleFactor - 1) * axisNormalized.z * axisNormalized.z;

    return scalingMatrix;

}

Mat3 Transform::CreateReflectionMat3OverPlane(const Vec3& axis) {

    return CreateScalingMat3longAxis(axis, -1);
}

Mat3 Transform::CreateOrthographicProjectionMat3AlongDirection(const Vec3& axis){
    return CreateScalingMat3longAxis(axis, 0);
}

Mat4 Transform::Create4x4AffineMatrixFrom3x3(const Mat3& M3x3, const Vec3& translation) {
    Vec3 lastColumItem = ((translation * M3x3) * -1) + translation;
    Mat4 affineMat4 = Mat4::Identity();
    for (int i = 0; i < M3x3.row; ++i)
    {
        for (int j = 0;j < M3x3.colum;++j) {
            affineMat4.set(i, j, M3x3.mat[i][j]);
        }
    }
    affineMat4.set(3, 0, lastColumItem.x);
    affineMat4.set(3, 1, lastColumItem.y);
    affineMat4.set(3, 2, lastColumItem.z);
    return affineMat4;
}

Mat4 Transform::CreateTranslationMat4(const Vec3& translation) {
    Mat4 translationMat4 = Mat4::Identity();
    translationMat4.set(3, 0, translation.x);
    translationMat4.set(3, 1, translation.y);
    translationMat4.set(3, 2, translation.z);

    return translationMat4;
}