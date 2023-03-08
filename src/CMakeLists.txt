cmake_minimum_required(VERSION 3.24)
project(traveling_salesman)

set(CMAKE_CXX_STANDARD 23)

add_executable(traveling_salesman main.cpp City.cpp City.h Instance.cpp Instance.h Solution.cpp Solution.h)
