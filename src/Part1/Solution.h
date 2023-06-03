//
// Created by louis on 14/02/23.
//

#ifndef TRAVELING_SALESMAN_SOLUTION_H
#define TRAVELING_SALESMAN_SOLUTION_H

#include <vector>
#include <string>
#include <unordered_map>
#include "../City.h"


class Solution {
public:
    Solution(Solution &solution);
    Solution(std::string filename);
    Solution();
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
    double evaluate();
    void randomize();
    void print();
    void compute_distances();
    static double convert(double);

private:
    Solution &solution;
    std::vector<City> sequence;
    double total_distance;
    std::vector<City> cities;
    std::unordered_map<std::pair<int, int>, double, pair_hash> distances;

    void convert();
};

#endif