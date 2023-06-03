//
// Created by hmoul on 20/05/2023.
//

#ifndef TRAVELING_SALESMAN_CALCULATE_H
#define TRAVELING_SALESMAN_CALCULATE_H

#include "../City.h"

double Calculate(const std::vector<City>& cities);
double CalculateDistance(const City& city1, const City& city2);

#endif //TRAVELING_SALESMAN_CALCULATE_H
