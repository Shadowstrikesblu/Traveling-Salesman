//
// Created by hmoul on 02/06/2023.
//

#include "Reinsertion.h"

//Considérant qu'on a 10 voisins, on obtient 36 voisins
//Reponse a la question 5.1 et 5.2

void reinsertion_par_index(std::vector<City>& cities, int index) {
    if (index <= cities.size() - 2) {
        int i = 0;
        int j = index + 1;
        reinsertion(cities, i, j);
    } else {
        int i = (index - 1) / (cities.size() - 2);
        int j = (index - 1) % (cities.size() - 2);
        if (j >= i - 1) {
            j = j + 2;
        }
        reinsertion(cities, i, j);
    }
}

void reinsertion(std::vector<City>& cities, int a, int b) {
    City city = cities[a];
    cities.erase(cities.begin() + a);
    cities.insert(cities.begin() + b, city);
}
