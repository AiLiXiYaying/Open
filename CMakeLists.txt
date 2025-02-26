cmake_minimum_required(VERSION 3.12)

project(OPENGL)

set(CMAKE_CXX_STANDARD 20)

#写在以下
include_directories(
    SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/include
)

#链接lib目录
link_directories(
    SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/lib
)

#设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(glStudy "main.cpp" "glad.c")

#链接到可执行程序中，形成一个完整程序
target_link_libraries(glStudy "glfw3dll.lib")
