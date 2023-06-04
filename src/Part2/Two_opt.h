//
// Created by hmoul on 03/06/2023.
//
#include <vector>
#include "../City.h"
#include <valarray>

#ifndef TRAVELING_SALESMAN_PERMUTATION_H
#define TRAVELING_SALESMAN_PERMUTATION_H


void Two_Opt(std::vector<City>& cities, int i, int j);
void Two_Opt_by_Index(std::vector<City>& cities, int neighbourIndex);

#endif //TRAVELING_SALESMAN_PERMUTATION_H
