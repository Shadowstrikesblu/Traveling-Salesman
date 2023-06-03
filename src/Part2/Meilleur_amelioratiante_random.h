//
// Created by hmoul on 03/06/2023.
//

#ifndef TRAVELING_SALESMAN_MEILLEUR_AMELIORATIANTE_RANDOM_H
#define TRAVELING_SALESMAN_MEILLEUR_AMELIORATIANTE_RANDOM_H

#include <random>
#include "../Part1/Calculate.h"
#include "../City.h"
#include "Meilleure_ameliorante.h"


std::vector<int> Meilleure(const std::vector<int>& sequence1, const std::vector<std::vector<int>>& sequence2, const std::vector<City>& cities);

#endif //TRAVELING_SALESMAN_MEILLEUR_AMELIORATIANTE_RANDOM_H
