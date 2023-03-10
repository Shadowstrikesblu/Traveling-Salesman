//
// Created by louis on 14/02/23.
//
#include "Instance.h"
#include <fstream>
#include <sstream>

Instance::Instance(std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string city_name;
            double latitude, longitude;
            ss >> city_name >> latitude >> longitude;
            City city(city_name, latitude, longitude);
            cities.push_back(city);
        }
        compute_distances();
    } else {
        throw std::runtime_error("Cannot open file " + filename);
    }
}

void Instance::compute_distances() {
    int n = cities.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            City city1 = cities[i];
            City city2 = cities[j];
            double distance = city1.distance(city2);
            distances[std::make_pair(i,j)] = distance;
            distances[std::make_pair(j,i)] = distance;
        }
    }
}

void Instance::write_solution(std::string filename, std::vector<City> sequence, double total_distance) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << total_distance << "\n";
        for (City city : sequence) {
            file << city.name << "\n";
        }
    } else {
        throw std::runtime_error("Cannot write to file " + filename);
    }
}

const std::vector<City> &Instance::getCities() const {
    return cities;
}

const std::unordered_map<std::pair<int, int>, double> &Instance::getDistances() const {
    return distances;
}
