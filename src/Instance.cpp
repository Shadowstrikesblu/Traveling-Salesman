//
// Created by louis on 14/02/23.
//
#include "Instance.h"
#include <fstream>
#include <sstream>

void Instance::compute_distances() {
    int n = cities.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            City city1 = cities[i];
            City city2 = cities[j];
            double distance = city1.distance(city2);
            distances.insert({{i, j}, distance});
            distances.insert({{j, i}, distance});
        }
    }
}

const std::vector<City> &Instance::getCities() const {
    return cities;
}

const std::unordered_map<std::pair<int, int>, double, Instance::pair_hash> & Instance::getDistances(
        std::pair<int, int> pair) const {
    return distances;
}