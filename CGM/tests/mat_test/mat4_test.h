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
        std::array<std::array<float, 4>, 4> myStdArr = { {
            { 1.0f,5.0f,4.0f,2.0f },
            { 7.0f,4.0f,7.1f,2.0f },
            { 3.0f,5.0f,-1.0f,2.0f },
            { 8.0f,6.0f,5.0f,9.0f }
        } };
        Mat4 matA(myStdArr);
        glm::vec3 position(1.0f, 2.0f, 3.0f);
        std::cout << "Position: (" << position.x << ", " << position.y << ", " << position.z << ")" << std::endl;
        std::cout << "=== Matrix A ===" << std::endl;
        matA.print("4x4");
    }
};
