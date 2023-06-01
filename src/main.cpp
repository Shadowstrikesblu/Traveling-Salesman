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

int main() {
    std::string filename = "../file.txt";
    std::vector<City> cities = ReadFile(filename);
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

    return 0;
}
