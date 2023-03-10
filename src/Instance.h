//
// Created by louis on 14/02/23.
//

#ifndef TRAVELING_SALESMAN_INSTANCE_H
#define TRAVELING_SALESMAN_INSTANCE_H


#include <string>
#include <vector>
#include <unordered_map>
#include "City.h"

class Instance {
public:
    Instance(std::string filename);
    void write_solution(std::string filename, std::vector<City> sequence, double total_distance);
    const std::unordered_map<std::pair<int, int>, double> &getDistances() const;
    const std::vector<City> &getCities() const;

private:
    std::vector<City> cities;
    std::unordered_map<std::pair<int,int>, double> distances;
    void compute_distances();
};

#endif