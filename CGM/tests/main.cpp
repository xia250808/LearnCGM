#include <cassert>
#include <iostream>
#include "mat_test/mat4_test.h"

// 手动添加 main 函数（程序入口）
int main() {
    std::cout << "开始运行测试..." << std::endl;
    mat4_test::test_mat4_multiplication();
    std::cout << "测试结束。" << std::endl;
    return 0;  // 返回 0 表示程序正常退出9
}
