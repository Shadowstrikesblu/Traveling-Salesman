//
// Created by louis on 14/02/23.
//

#include "Solution.h"
#include <algorithm>
#include <random>
#include <fstream>
#include <iostream>
#include "Instance.h"

Solution::Solution(Instance &instance) : instance(instance), sequence(instance.getCities()) {}

double Solution::evaluate() {
    double distance = 0;
    int n = sequence.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        auto city_pair = std::make_pair(sequence[i].id, sequence[j].id);
        auto distances = instance.getDistances(city_pair);
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

void Solution::read(std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        double total_distance;
        file >> total_distance;
        std::string line;
        std::vector<City> new_sequence;
        while (std::getline(file, line)) {
            for (City city : instance.getCities()) {
                if (city.name == line) {
                    new_sequence.push_back(city);
                    break;
                }
            }
        }
        sequence = new_sequence;
        this->total_distance = total_distance;
    } else {
        throw std::runtime_error("Cannot open file " + filename);
    }
}