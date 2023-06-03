//
// Created by hmoul on 03/06/2023.
//

#ifndef TRAVELING_SALESMAN_ALOGRITHME_DESCENTE_H
#define TRAVELING_SALESMAN_ALOGRITHME_DESCENTE_H


#include <vector>
#include "../City.h"
#include <limits>

std::vector<int> Descente(const std::vector<int>& s, const std::vector<std::vector<int>>& voisinage, const std::vector<City>& cities);


#endif //TRAVELING_SALESMAN_ALOGRITHME_DESCENTE_H
