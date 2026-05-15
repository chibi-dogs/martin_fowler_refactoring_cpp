cmake_minimum_required(VERSION 4.0)
project(martin_fowler_refactoring)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src)
add_subdirectory(tests)
add_executable(martin_fowler_refactoring main.cpp)

