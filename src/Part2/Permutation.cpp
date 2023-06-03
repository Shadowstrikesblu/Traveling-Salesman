//
// Created by hmoul on 03/06/2023.
//

#include "Permutation.h"

void Permutation(std::vector<int>& sequence, int cityIndex1, int cityIndex2) {
    int size = sequence.size();
    int i = (cityIndex1 + 1) % size;
    int j = (cityIndex2 + 1) % size;

    // Swap the cities in the sequence
    while (i != j) {
        std::swap(sequence[i], sequence[j]);
        i = (i + 1) % size;
        j = (j - 1 + size) % size;
    }
}
