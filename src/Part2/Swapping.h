//
// Created by hmoul on 02/06/2023.
//

#ifndef TRAVELING_SALESMAN_SWAPPING_H
#define TRAVELING_SALESMAN_SWAPPING_H

#include "../City.h"
#include <vector>

void Swapping(std::vector<City>& cities, int cityIndex1, int cityIndex2);
void Swapping_by_Index(std::vector<City>& cities, int neighbourIndex);
#endif //TRAVELING_SALESMAN_SWAPPING_H
