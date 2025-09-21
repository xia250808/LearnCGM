// tests/matrix4x4_test.cpp
#include <cassert>
#include <iostream>
#include<array>
#include <glm/glm.hpp> 
#include "mat/mat4.h"


class mat4_test
{
public:
    static void test_mat4_multiplication() {
        array<float, 4> matrix4x4Arow1 = { 1.0f,5.0f,4.0f,2.0f };
        array<float, 4> matrix4x4Arow2 = { 7.0f,4.0f,7.0f,2.0f };
        array<float, 4> matrix4x4Arow3 = { 3.0f,5.0f,-1.0f,2.0f };
        array<float, 4> matrix4x4Arow4 = { 8.0f,6.0f,5.0f,9.0f };
        Mat4 matA(matrix4x4Arow1, matrix4x4Arow2, matrix4x4Arow3, matrix4x4Arow4);
        glm::vec3 position(1.0f, 2.0f, 3.0f);
        std::cout << "Position: (" << position.x << ", " << position.y << ", " << position.z << ")" << std::endl;
        std::cout << "GLM Version: " << GLM_VERSION << std::endl;  // 输出 GLM 版本（如 100700 表示 1.7.0）
        std::cout << "=== 矩阵 A ===" << std::endl;
        matA.print("4x4");
    }
};
