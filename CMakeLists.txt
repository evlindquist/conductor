cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(conductor VERSION 0.1)

include_directories(game)

add_executable(conductor main.cpp)