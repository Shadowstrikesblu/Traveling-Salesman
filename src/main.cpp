#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "City.h"
#include <cmath>
#include "Part1/Solution.h"
#include "Part1/Sort.h"
#include "Part1/Random.h"
#include "Part1/Calculate.h"
#include "Part1/Print.h"
#include "Part1/ReadFile.h"
#include "Part2/Swapping.h"
#include "Part2/Reinsertion.h"
#include "Part2/Permutation.h"

int main() {
    std::string filename = "../file.txt";
    std::vector<City> cities = ReadFile(filename);
    std::vector<int> cityOrder = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (cities.empty()) {
        return 1;
    }
    // Réorganise les villes en fonction de la distance
    City startCity = cities[0];
    orderCitiesByDistance(cities, startCity);
    // Affiche le nouvel ordre des villes
    Print(cities);
    // Calcule des distances
    Calculate(cities);
    // Solution Aléatoire
    RandomizeCityOrder(cities);
    std::cout << "Solution Aleatoire:" << std::endl;
    Print(cities);
    Swapping(cityOrder,2,5);
    std::cout <<"Ordre Ville echange" << std::endl;
    for (int city : cityOrder) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
    reinsertion_par_index(cityOrder,3);
    Permutation(cityOrder,2,5);

    return 0;
}
