#include <iostream>
#include <vector>
#include <fstream>
#include "City.h"
#include "Part1/Sort.h"
#include "Part1/Random.h"
#include "Part1/Calculate.h"
#include "Part1/Print.h"
#include "Part1/ReadFile.h"
#include "Part2/Swapping.h"
#include "Part2/Reinsertion.h"
#include "Part2/Two_opt.h"
#include "Part2/Meilleure_Ameliorante.h"
#include "Part2/Alogrithme_Descente.h"
#include "Part2/Premiere_ameliorante.h"
#include "Complement/GetCityIndices.h"

int main() {
    std::string filename = "../file.txt";
    std::vector<City> cities = ReadFile(filename);
    std::vector<City> randomcities = ReadFile(filename);
    //Un vecteur pour chaque fonction que l'on déclare dans le main
    std::vector<City> cities1 = ReadFile(filename);
    std::vector<City> cities2 = ReadFile(filename);
    std::vector<City> cities4 = ReadFile(filename);
    std::vector<City> cities5 = ReadFile(filename);
    std::vector<City> cities6 = ReadFile(filename);
    // Un ordre de ville désigné aléatoirement
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
    RandomizeCityOrder(randomcities);
    std::cout << "Solution Aleatoire ---> ";
    Print(randomcities);
    // Nouvelle fonction
    std::vector<int> cityOrder(cities.size());
    for (int i = 0; i < cities.size(); ++i) {
        cityOrder[i] = i;
    }
    Swapping(cities1, 2, 5);
    std::cout << "Sequence modifiee par la fonction Echange: ";
    Print(cities);
    // Nouvelle fonction
    Swapping_by_Index(cities2, 4);
    std::cout << "Sequence modifiee par la fonction Echange_par_index: ";
    Print(cities);
    // Nouvelle fonction
    reinsertion_par_index(cities, 7);
    std::cout << "Sequence modifiee par Reinsertion par index: ";
    Print(cities);
    // Nouvelle fonction
    Two_Opt(cities4, 2, 5);
    std::cout << "Sequence modifie par Two_Opt: ";
    Print(cities4);
    Two_Opt_by_Index(cities5, 5);
    std::cout << "Sequence modifie par Two_Opt_by_Index: ";
    Print(cities5);
    std::vector<std::vector<int>> sequence2;
    std::ifstream sequenceFile("file.txt");
    int swapIndex1, swapIndex2;
    while (sequenceFile >> swapIndex1 >> swapIndex2) {
        sequence2.push_back({swapIndex1, swapIndex2});
    }
    sequenceFile.close();
    std::vector<int> meilleure_solution = Meilleure_Ameliorante(cities6, sequence2);
    std::cout << "Solution trouvee par la fonction Meilleure_Ameliorante: ";
    PrintOrder(meilleure_solution);
    std::vector<int> algorithme_descente = Descente(cities6, sequence2);
    std::cout << "Solution trouvee par la fonction Algorithme_Descente: ";
    PrintOrder(algorithme_descente);
    std::vector<int> bestSolution = Premiere(cities6, sequence2);
    std::cout << "Solution trouvee par la fonction Premiere_ameliorante: ";
    PrintOrder(bestSolution);
}
