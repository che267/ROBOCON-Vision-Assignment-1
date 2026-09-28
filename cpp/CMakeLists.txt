cmake_minimum_required(VERSION 3.10)
project(RoboconVisionCpp)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 OpenCV 和 Eigen3
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

# 包含头文件目录
include_directories(${OpenCV_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIRS} include)

# 指定源文件
add_executable(process_video src/main.cpp src/transform.cpp)

# 链接 OpenCV 库
target_link_libraries(process_video ${OpenCV_LIBS})

