project("c_learn")
cmake_minimum_required(VERSION 3.0)
# 让生成的文件可以被调试
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++20")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# 搜索源码文件目录
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)
# 指定头文件所在位置
include_directories(${PROJECT_SOURCE_DIR}/include())
# 指定可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 指定库路径
link_directories(${PROJECT_SOURCE_DIR}/lib)
# 添加待编译文件
add_executable(app ${SRC_LIST})


