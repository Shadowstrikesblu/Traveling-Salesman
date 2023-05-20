#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "City.h"
#include <cmath>
#include "Part1/Solution.h"
#include "Part1/Sort.h"
#include "Part1/Random.h"

int main() {
    std::ifstream file("../file.txt");
    std::vector<City> cities;
    std::string line;

    if (!std::getline(file, line)) {
        std::cerr << "Failed to read the size of the input." << std::endl;
        return 1;
    }
    int size;
    try {
        size = std::stoi(line);
    } catch (const std::invalid_argument& ex) {
        std::cerr << "Invalid input size: " << line << std::endl;
        return 1;
    }

    // Lis les informations du fichier txt
    for (int i = 0; i < size; i++) {
        std::getline(file, line);
        std::istringstream ss(line);
        double latitude, longitude;
        std::string name;
        ss >> name >> latitude >> longitude;
        if (ss.fail()) {
            std::cerr << "Invalid input format in line " << i + 2 << std::endl;
            return 1;
        }
        cities.emplace_back(i, name, latitude, longitude);
    }

    file.close();
//    std::vector<City> cities = Readfile("../file.txt");
    // Arrange les cités en fonction des distances entre chacunes
    City startCity = cities[0];
    orderCitiesByDistance(cities, startCity);
    // Affiche le nouvel ordre des villes
    std::cout << "Solution:" << std::endl;
    for (const City& city : cities) {
        std::cout << city.id  << std::endl;
    }

    // Calculate average distance
    double totalDistance = 0.0;
    int count = 0;
    double R = 6378.137;

    for (int i = 0; i < cities.size() - 1; i++) {
        double v_longitude = Solution::convert(cities[i].latitude);
        double v1_longitude = Solution::convert(cities[i + 1].latitude);
        double v_latitude = Solution::convert(cities[i].longitude);
        double v1_latitude = Solution::convert(cities[i + 1].longitude);
        double distance = R * acos(sin(v_latitude) * sin(v1_latitude) +
                                   cos(v_latitude) * cos(v1_latitude) *
                                   cos(v_longitude - v1_longitude));
        std::cout << "Distance entre les villes " << i << " et " << i + 1 << ": " << distance << std::endl;
        totalDistance += distance;
        count++;
    }

    double averageDistance = totalDistance / count;
    std::cout << "Distance moyenne: " << averageDistance << std::endl;

    //Calcule un ordre aléatoire
    RandomizeCityOrder(cities);
    std::cout << "Solution Aleatoire:" << std::endl;
    for (const City& city : cities) {
        std::cout << city.id  << std::endl;
    }

    return 0;
}
