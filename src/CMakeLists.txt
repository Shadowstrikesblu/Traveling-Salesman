cmake_minimum_required(VERSION 3.24)
project(traveling_salesman)

set(CMAKE_CXX_STANDARD 23)

add_executable(traveling_salesman main.cpp City.cpp City.h Part1/Solution.cpp Part1/Solution.h Part1/Sort.cpp Part1/Sort.h Part1/Random.cpp Part1/Random.h)
