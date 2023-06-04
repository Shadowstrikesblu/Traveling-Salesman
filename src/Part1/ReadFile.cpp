//
// Created by hmoul on 20/05/2023.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "ReadFile.h"
std::vector<City> ReadFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<City> cities;
    std::string line;

    if (!std::getline(file, line)) {
        std::cerr << "Erreur au niveau du nom du fichier" << std::endl;
        return cities;
    }
    int size;
    try {
        size = std::stoi(line);
    } catch (const std::invalid_argument& ex) {
        std::cerr << "Erreur au niveau de la taille du fichier " << line << std::endl;
        return cities;
    }

    for (int i = 0; i < size; i++) {
        std::getline(file, line);
        std::istringstream ss(line);
        double latitude, longitude;
        std::string name;
        ss >> name >> latitude >> longitude;
        if (ss.fail()) {
            std::cerr << "Mauvaise entrée " << i + 2 << std::endl;
            return cities;
        }
        cities.emplace_back(i, name, latitude, longitude);
    }

    file.close();
    return cities;
}
