//
// Created by hmoul on 03/06/2023.
//

#include "Two_opt.h"

//Reponse a la question 6.1
void Two_Opt(std::vector<City>& cities, int i, int j) {
    int size = cities.size();
    while (i < j) {
        std::swap(cities[i], cities[j]);
        i++;
        j--;
    }
}

// Reponse a la question 6.2
void Two_Opt_by_Index(std::vector<City>& cities, int neighbourIndex) {
    int n = (1 + sqrt(1 + 8 * neighbourIndex)) / 2;
    int i = neighbourIndex - (n * (n - 1)) / 2;
    int j = cities.size() - n + 1;
    Two_Opt(cities, i, j);
}
