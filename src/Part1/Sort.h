#ifndef SORT_H
#define SORT_H

#include "../City.h"
#include <algorithm>

bool sortByDistance(const City& city1, const City& city2, const City& startCity);

void orderCitiesByDistance(std::vector<City>& cities, const City& startCity);

#endif // SORT_H
