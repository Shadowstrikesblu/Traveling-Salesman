//
// Created by louis on 14/02/23.
//

#include "Solution.h"
#include <algorithm>
#include <random>
#include <fstream>
#include <iostream>


Solution::Solution(Solution &solution1) : solution(solution1), sequence(solution1.getCities()) {}

double Solution::evaluate() {
    double distance = 0;
    int n = sequence.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        auto city_pair = std::make_pair(sequence[i].id, sequence[j].id);
        auto distances = solution.getDistances(city_pair);
        for (auto& pair : distances) {
            distance += pair.second;
        }
    }
    total_distance = distance;
    return distance;
}

void Solution::randomize() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(sequence.begin(), sequence.end(), g);
    evaluate();
}

void Solution::print() {
    for (City city : sequence) {
        std::cout << city.name << "\n";
    }
    std::cout << "Total distance: " << total_distance << "\n";
}

//void Solution::compute_distances() {
//    int n = cities.size();
//    for (int i = 0; i < n; i++) {
//        for (int j = i+1; j < n; j++) {
//            City city1 = cities[i];
//            City city2 = cities[j];
//            double distance = city1.distance(city2);
//            distances.insert({{i, j}, distance});
//            distances.insert({{j, i}, distance});
//        }
//    }
//}

double Solution::convert(double a){
    double pi = 3.141592;
    a = (pi * a / 180);
    return a;

}

const std::vector<City> &Solution::getCities() const {
    return cities;
}

const std::unordered_map<std::pair<int, int>, double, Solution::pair_hash> & Solution::getDistances(
        std::pair<int, int> pair) const {
    return distances;
}