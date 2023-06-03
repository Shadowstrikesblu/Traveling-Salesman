//
// Created by hmoul on 02/06/2023.
//

#include <vector>
#include "Reinsertion.h"

//Considérant qu'on a 10 voisins, on obtient 36 voisins

void reinsertion_par_index(std::vector<int>& s, int index) {
    if (index <= s.size() - 2) {
        int i = 0;
        int j = index + 1;
        reinsertion(s, i, j);
    } else {
        int i = (index - 1) / (s.size() - 2);
        int j = (index - 1) % (s.size() - 2);
        if (j >= i - 1) {
            j = j + 2;
        }
        reinsertion(s, i, j);
    }
}

void reinsertion(std::vector<int> &vector, int i, int j) {

}

