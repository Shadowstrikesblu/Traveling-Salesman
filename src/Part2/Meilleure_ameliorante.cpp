//
// Created by hmoul on 03/06/2023.
//

#include "Meilleure_ameliorante.h"

std::vector<int> Meilleure(const std::vector<int>& sequence1, const std::vector<std::vector<int>>& sequence2, const std::vector<City>& cities) {
    std::vector<int> bestSolution = sequence1;
    double bestDistance = DistanceSequence(sequence1, cities);

    for (const std::vector<int>& voisin : sequence2) {
        double neighborDistance = DistanceSequence(voisin, cities);

        if (neighborDistance < bestDistance) {
            bestSolution = voisin;
            bestDistance = neighborDistance;
        }
    }

    return bestSolution;
}


double DistanceSequence(const std::vector<int>& sequence, const std::vector<City>& cities) {
    double distance = 0.0;
    for (size_t i = 0; i < sequence.size() - 1; i++) {
        City cityA = cities[sequence[i]];
        City cityB = cities[sequence[i + 1]];
        distance += CalculateDistance(cityA, cityB); // Assuming you have a function named getDistance to calculate distance between two cities
    }
    return distance;
}

