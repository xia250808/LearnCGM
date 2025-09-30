#include <cassert>
#include <iostream>
#include "mat_test/mat4_test.h"
#include "eul_test/eul_test.h"

// 手动添加 main 函数（程序入口）
int main() {
    std::cout << "START TEST..." << std::endl;
    //mat4_test::test_mat4_multiplication();
    transRotation_test::tests();
    std::cout << "TEST  END" << std::endl;
    return 0;
}
