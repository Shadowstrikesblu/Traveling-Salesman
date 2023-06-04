//
// Created by hmoul on 03/06/2023.
//
#include <vector>

#ifndef TRAVELING_SALESMAN_PERMUTATION_H
#define TRAVELING_SALESMAN_PERMUTATION_H


void Two_Opt(std::vector<int>& sequence, int cityIndex1, int cityIndex2);
void Two_Opt_by_Index(std::vector<int>& sequence, int neighbourIndex);

#endif //TRAVELING_SALESMAN_PERMUTATION_H
