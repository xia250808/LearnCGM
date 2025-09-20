// tests/matrix4x4_test.cpp
#include <cassert>
#include <iostream>
#include<array>
#include "mat/mat4.h"

// 测试函数（无需 static，需被 main 调用）
void test_matrix_multiplication() {
    array<float,4> matrix4x4Arow1 = { 1.0f,5.0f,4.0f,2.0f };
    array<float, 4> matrix4x4Arow2 = { 7.0f,4.0f,7.0f,2.0f };
    array<float, 4> matrix4x4Arow3 = { 3.0f,5.0f,-1.0f,2.0f };
    array<float, 4> matrix4x4Arow4 = { 8.0f,6.0f,4.0f,9.0f };
    Mat4 mat1(matrix4x4Arow1, matrix4x4Arow2, matrix4x4Arow3, matrix4x4Arow4);
    mat1.print("4x4");
    std::cout << "=== 矩阵 A ===" << std::endl;
    std::cout << "GLM 矩阵数据:\n";
}

// 手动添加 main 函数（程序入口）
int main() {
    std::cout << "开始运行测试..." << std::endl;
    test_matrix_multiplication();  // 调用测试函数
    std::cout << "测试结束。" << std::endl;
    return 0;  // 返回 0 表示程序正常退出
}