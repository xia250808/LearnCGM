# CMakeList.txt: CGM 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CGM")
add_subdirectory(tests)
# 1. 递归收集所有 .cpp 文件（包括子目录）
file(GLOB_RECURSE CGM_SOURCES 
    "${CMAKE_SOURCE_DIR}/src/**/*.cpp"  # 匹配 src/ 下所有 .cpp 文件（包括 mat/、transform/、vec/ 子目录）
)

# 定义静态库（库名 CGM，类型 STATIC）
add_library(CGM STATIC ${CGM_SOURCES})

target_include_directories(CGM PUBLIC 
    "${CMAKE_SOURCE_DIR}/include"  # 公共头文件目录
)

# 4. 可选：打印调试信息（验证路径是否正确）
message(STATUS "源文件列表：${CGM_SOURCES}")
message(STATUS "CMAKE_SOURCE_DIR：${CMAKE_SOURCE_DIR}")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CGM PROPERTY CXX_STANDARD 20)
endif()
