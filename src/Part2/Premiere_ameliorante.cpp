//
// Created by hmoul on 03/06/2023.
//

#include "Premiere_ameliorante.h"
#include "../Complement/GetCityIndices.h"
#include "Meilleure_Ameliorante.h"

std::vector<int> Premiere(const std::vector<City>& cities, const std::vector<std::vector<int>>& sequence2) {
    std::vector<int> bestSolution = GetCityIndices(cities);
    double bestDistance = DistanceSequence(bestSolution, cities);

    for (const std::vector<int>& voisin : sequence2) {
        double neighborDistance = DistanceSequence(voisin, cities);

        if (neighborDistance < bestDistance) {
            bestSolution = voisin;
            break;
        }
    }

    return bestSolution;
}

