cmake_minimum_required(VERSION 3.20)
project(Lesson8)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lesson8 main.cpp)
target_link_libraries(Lesson8 gtest gtest_main)
