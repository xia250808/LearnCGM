# tests/CMakeLists.txt
# 启用 CTest（测试运行器）
include(CTest)
enable_testing()
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
project("cgm_test")
add_executable(cgm_test 
    "mat/mat4_test.cpp"
)

target_link_libraries(cgm_test PRIVATE 
    CGM  # 主库名（与 add_library 定义的名称一致）
)

add_test(
    NAME mat4_test
    COMMAND cgm_test --test=mat4_test  # 通过命令行参数指定运行的测试组
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}  # 测试文件工作目录
)