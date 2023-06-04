#include <iostream>
#include <vector>
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

int main() {
    std::string filename = "../file.txt";
    std::vector<City> cities = ReadFile(filename);
    //Un ordre de ville désigné aléatoirement
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
    //Nouvelle fonction
    std::vector<int> cityOrder = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Swapping(cityOrder, 2, 5);
    std::cout << "Sequence modifiee par la fonction Echange: ";
    for (int city : cityOrder) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
    //Nouvelle fonction
    std::vector<int> cityOrder2= cityOrder ;
    Swapping(cityOrder, 2, 5);
    std::cout << "Sequence modifiee par la fonction Echange: ";
    for (int city : cityOrder2) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
    //Nouvelle fonction
    std::vector<int> cityOrder3 = cityOrder;
    reinsertion_par_index(cityOrder3,3);
    std::cout << "Sequence modifiee par Reinsertion par index: ";
    for (int city : cityOrder3) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
    //Nouvelle fonction
    std::vector<int> cityOrder4 = cityOrder;
    Two_Opt(cityOrder4, 2, 5);
    std::cout << "Sequence modifie par Two_Opt: ";
    for (int city : cityOrder4) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
    Two_Opt_by_Index(cityOrder4, 5);
    std::cout << "Sequence modifie par Two_Opt_by_Index: ";
    for (int city : cityOrder4) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
    std::vector<int> cityOrder5 = cityOrder;
    std::vector<std::vector<int>> sequence2 = {{1, 3, 0, 2, 4, 5, 6, 7, 8, 9}, {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}};
    std::vector<int> meilleure_solution = Meilleure_Ameliorante(cityOrder5, sequence2, cities);
    std::cout << "Solution trouvee par la fonction Meilleure_Ameliorante: ";
    for (int city : meilleure_solution) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
    std::vector<int> cityOrder6 = cityOrder;
    std::vector<std::vector<int>> voisinage = {{2,4,7,8,9,1,3,5,0,6}, {1,2,3,7,8,9,0,4,5,6}};
    std::vector<int> algorithme_descente = Descente(cityOrder6, voisinage, cities);

    std::cout << "Solution trouvee par la fonction Algorithme_Descente: ";
    for (int city : algorithme_descente) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
    std::vector<int> bestSolution = Premiere(cityOrder6, sequence2, cities);

    std::cout << "Solution trouvee par la fonction Premiere_ameliorante: ";
    for (int city : bestSolution) {
        std::cout << city << " ";
    }
    std::cout << std::endl;

    return 0;

    return 0;

    return 0;
}
