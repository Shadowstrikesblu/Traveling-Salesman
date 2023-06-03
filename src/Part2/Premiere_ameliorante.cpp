//
// Created by hmoul on 03/06/2023.
//

#include "Premiere_ameliorante.h"
#include "Meilleure_ameliorante.h"

std::vector<int> Premiere(const std::vector<int>& sequence1, const std::vector<std::vector<int>>& sequence2, const std::vector<City>& cities) {
    std::vector<int> bestSolution = sequence1;
    double bestDistance = DistanceSequence(sequence1, cities);

    for (const std::vector<int>& voisin : sequence2) {
        double neighborDistance = DistanceSequence(voisin, cities);

        if (neighborDistance < bestDistance) {
            bestSolution = voisin;
            break;
        }
    }

    return bestSolution;
}

