//
// Created by hmoul on 04/06/2023.
//

#include "GetCityIndices.h"

std::vector<int> GetCityIndices(const std::vector<City>& cities) {
    std::vector<int> city_indices(cities.size());
    for (int i = 0; i < cities.size(); ++i) {
        city_indices[i] = i;
    }
    return city_indices;
}
