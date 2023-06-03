//
// Created by hmoul on 03/06/2023.
//

#ifndef TRAVELING_SALESMAN_MEILLEURE_AMELIORANTE_H
#define TRAVELING_SALESMAN_MEILLEURE_AMELIORANTE_H


#include <vector>
#include "../City.h"
#include "../Part1/Calculate.h"

std::vector<int> Meilleure(const std::vector<int>& sequence1, const std::vector<std::vector<int>>& sequence2, const std::vector<City>& cities);
double DistanceSequence(const std::vector<int>& sequence, const std::vector<City>& cities);


#endif //TRAVELING_SALESMAN_MEILLEURE_AMELIORANTE_H
