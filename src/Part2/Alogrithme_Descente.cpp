//
// Created by hmoul on 03/06/2023.
//

#include "Alogrithme_Descente.h"
#include "../Complement/GetCityIndices.h"
#include "Meilleure_Ameliorante.h"


std::vector<int> Descente(const std::vector<City>& cities, const std::vector<std::vector<int>>& voisinage) {
    std::vector<int> solution = GetCityIndices(cities);
    double distance_solution = DistanceSequence(solution, cities);
    std::vector<int> meilleure_solution;
    double meilleure_distance = std::numeric_limits<double>::infinity();

    while (meilleure_distance > distance_solution) {
        meilleure_solution = solution;
        meilleure_distance = distance_solution;
        solution = Meilleure_Ameliorante(cities, voisinage);
        distance_solution = DistanceSequence(solution, cities);
    }

    return meilleure_solution;
}
