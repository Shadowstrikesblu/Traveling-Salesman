//
// Created by hmoul on 04/06/2023.
//

#include "Meilleure_Ameliorante.h"
#include "../Part1/Calculate.h"
#include "../Complement/GetCityIndices.h"
#include <vector>

std::vector<int> Meilleure_Ameliorante(const std::vector<City>& cities, const std::vector<std::vector<int>>& sequence2) {
    std::vector<int> meilleure_solution = GetCityIndices(cities);
    double meilleure_distance = DistanceSequence(meilleure_solution, cities);

    for (const std::vector<int>& solution_voisine : sequence2) {
        double distance_voisine = DistanceSequence(solution_voisine, cities);

        if (distance_voisine < meilleure_distance) {
            meilleure_solution = solution_voisine;
            meilleure_distance = distance_voisine;
        }
    }

    return meilleure_solution;
}

double DistanceSequence(const std::vector<int>& sequence, const std::vector<City>& cities) {
    double distance = 0.0;
    for (size_t i = 0; i < sequence.size() - 1; i++) {
        City cityA = cities[sequence[i]];
        City cityB = cities[sequence[i + 1]];
        distance += CalculateDistance(cityA, cityB);
    }
    return distance;
}