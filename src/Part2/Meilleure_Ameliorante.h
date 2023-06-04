//
// Created by hmoul on 04/06/2023.
//

#ifndef TRAVELING_SALESMAN_MEILLEURE_AMELIORANTE_H
#define TRAVELING_SALESMAN_MEILLEURE_AMELIORANTE_H

#include "Meilleure_Ameliorante.h"
#include "../City.h"
#include <vector>

std::vector<int> Meilleure_Ameliorante(const std::vector<City>& cities, const std::vector<std::vector<int>>& sequence2);
double DistanceSequence(const std::vector<int>& sequence, const std::vector<City>& cities);


#endif //TRAVELING_SALESMAN_MEILLEURE_AMELIORANTE_H
