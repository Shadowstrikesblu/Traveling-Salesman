//
// Created by hmoul on 19/05/2023.
//

#include "Sort.h"
#include "../City.h"
#include <algorithm>

bool sortByDistance(const City& city1, const City& city2, const City& startCity) {
    double distance1 = startCity.distance(city1);
    double distance2 = startCity.distance(city2);
    return distance1 < distance2;
}

void orderCitiesByDistance(std::vector<City>& cities, const City& startCity) {
    std::sort(cities.begin(), cities.end(), [&](const City& city1, const City& city2) {
        return sortByDistance(city1, city2, startCity);
    });
}
