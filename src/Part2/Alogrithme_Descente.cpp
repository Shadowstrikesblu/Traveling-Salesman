//
// Created by hmoul on 03/06/2023.
//

#include "Alogrithme_Descente.h"
#include "Meilleure_Ameliorante.h"



std::vector<int> Descente(const std::vector<int>& s, const std::vector<std::vector<int>>& voisinage, const std::vector<City>& cities) {
    std::vector<int> solution = s;
    double distance_solution = DistanceSequence(solution, cities);
    std::vector<int> meilleure_solution;
    double meilleure_distance = std::numeric_limits<double>::infinity();

    while (meilleure_distance > distance_solution) {
        meilleure_solution = solution;
        meilleure_distance = distance_solution;
        solution = Meilleure_Ameliorante(solution, voisinage, cities);
        distance_solution = DistanceSequence(solution, cities);
    }

    return meilleure_solution;
}
