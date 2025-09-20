// tests/matrix4x4_test.cpp
#include <cassert>
#include <iostream>
#include<array>
#include "mat/mat4.h"


class mat4_test
{
public:
    static void test_mat4_multiplication() {
        array<float, 4> matrix4x4Arow1 = { 1.0f,5.0f,4.0f,2.0f };
        array<float, 4> matrix4x4Arow2 = { 7.0f,4.0f,7.0f,2.0f };
        array<float, 4> matrix4x4Arow3 = { 3.0f,5.0f,-1.0f,2.0f };
        array<float, 4> matrix4x4Arow4 = { 8.0f,6.0f,5.0f,9.0f };
        Mat4 mat1(matrix4x4Arow1, matrix4x4Arow2, matrix4x4Arow3, matrix4x4Arow4);
        std::cout << "=== 矩阵 A ===" << std::endl;
        mat1.print("4x4");
    }
};
