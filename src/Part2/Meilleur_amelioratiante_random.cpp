//
// Created by hmoul on 03/06/2023.
//

#include "Meilleur_amelioratiante_random.h"

std::vector<int> Best_Random(const std::vector<int>& sequence1, const std::vector<std::vector<int>>& sequence2, const std::vector<City>& cities) {
    std::vector<int> bestSolution = sequence1;
    double bestDistance = DistanceSequence(sequence1, cities);

    std::random_device rd;
    std::mt19937 generator(rd());

    std::vector<std::vector<int>> randomizedNeighbors = sequence2;
    std::shuffle(randomizedNeighbors.begin(), randomizedNeighbors.end(), generator);

    for (const std::vector<int>& voisin : randomizedNeighbors) {
        double neighborDistance = DistanceSequence(voisin, cities);

        if (neighborDistance < bestDistance) {
            bestSolution = voisin;
            bestDistance = neighborDistance;
        }
    }

    return bestSolution;
}
