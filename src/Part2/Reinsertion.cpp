//
// Created by hmoul on 02/06/2023.
//

#include <vector>
#include "Reinsertion.h"

//Considérant qu'on a 10 voisins, on obtient 36 voisins
//Reponse a la question 5.1 et 5.2

void reinsertion_par_index(std::vector<int>& sequence, int index) {
    if (index <= sequence.size() - 2) {
        int i = 0;
        int j = index + 1;
        reinsertion(sequence, i, j);
    } else {
        int i = (index - 1) / (sequence.size() - 2);
        int j = (index - 1) % (sequence.size() - 2);
        if (j >= i - 1) {
            j = j + 2;
        }
        reinsertion(sequence, i, j);
    }
}

void reinsertion(std::vector<int>& sequence, int a, int b) {
    int city = sequence[a];
    sequence.erase(sequence.begin() + a);
    sequence.insert(sequence.begin() + b, city);
}
