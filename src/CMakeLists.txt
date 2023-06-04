cmake_minimum_required(VERSION 3.24)
project(traveling_salesman)

set(CMAKE_CXX_STANDARD 23)

add_executable(traveling_salesman main.cpp City.cpp City.h Part1/Solution.cpp Part1/Solution.h Part1/Sort.cpp Part1/Sort.h Part1/Random.cpp Part1/Random.h Part1/Calculate.cpp Part1/Calculate.h Part1/Print.cpp Part1/Print.h Part1/ReadFile.cpp Part1/ReadFile.h Part2/Swapping.h Part2/Swapping.cpp Part2/Reinsertion.h Part2/Reinsertion.cpp Part2/Two_opt.h Part2/Two_opt.cpp Part2/Alogrithme_Descente.h Part2/Alogrithme_Descente.cpp Part2/Premiere_ameliorante.h Part2/Premiere_ameliorante.cpp Part2/Meilleur_amelioratiante_random.h Part2/Meilleur_amelioratiante_random.cpp   Part2/Meilleure_Ameliorante.cpp Part2/Meilleure_Ameliorante.h Complement/GetCityIndices.h Complement/GetCityIndices.cpp)
