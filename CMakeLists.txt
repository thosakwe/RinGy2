cmake_minimum_required(VERSION 3.5)
project(RinGy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/RinGyVM.cpp src/RinGyVM.h)
add_executable(RinGy ${SOURCE_FILES})