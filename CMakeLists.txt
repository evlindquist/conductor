cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options()
add_compile_options(-I /Users/evanlindquist/Documents/conductor/)

project(conductor VERSION 0.1)

include_directories(game)
include_directories(strategy)

set(CMAKE_BUILD_TYPE Debug)

add_executable(conductor main.cpp)