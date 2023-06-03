//
// Created by hmoul on 02/06/2023.
//

#include "Swapping.h"


#include <iostream>
#include <vector>

void Swapping(std::vector<int>& cities, int cityIndex1, int cityIndex2) {
    if (cityIndex1 < 0 || cityIndex1 >= cities.size() || cityIndex2 < 0 || cityIndex2 >= cities.size()) {
        std::cerr << "Erreur d'indice de villes" << std::endl;
        return;
    }

    std::swap(cities[cityIndex1], cities[cityIndex2]);
}