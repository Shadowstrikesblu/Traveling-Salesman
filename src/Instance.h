//
// Created by louis on 14/02/23.
//

#ifndef TRAVELING_SALESMAN_INSTANCE_H
#define TRAVELING_SALESMAN_INSTANCE_H


#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>

#include "City.h"

class Instance {
public:
    Instance(std::string filename);
    Instance();
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };
    const std::unordered_map<std::pair<int, int>, double, pair_hash> &getDistances(std::pair<int, int> pair) const;
    const std::vector<City>& getCities() const;

private:
    std::vector<City> cities;
    std::unordered_map<std::pair<int, int>, double, pair_hash> distances;
    void compute_distances();

};






#endif