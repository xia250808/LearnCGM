# tests/CMakeLists.txt
# 启用 CTest（测试运行器）
include(CTest)
enable_testing()
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
project("cgm_test")
add_executable(cgm_test  "main.cpp")
target_include_directories(cgm_test PRIVATE 
    "${CMAKE_SOURCE_DIR}/tests/external"
)

target_link_libraries(cgm_test PRIVATE 
    CGM  # 主库名（与 add_library 定义的名称一致）
)