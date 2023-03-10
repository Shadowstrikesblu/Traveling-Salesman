//
// Created by louis on 14/02/23.
//

#include "Solution.h"
#include <algorithm>
#include <random>
#include <fstream>
#include <iostream>

Solution::Solution(Instance &instance) : instance(instance), sequence(instance.getCities()) {}

double Solution::evaluate() {
    double distance = 0;
    int n = sequence.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        distance += instance.getDistances(sequence[i], sequence[j]);
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

void Solution::write(std::string filename) {
    instance.write_solution(filename, sequence, total_distance);
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