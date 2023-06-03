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
        std::cerr << "Failed to read the size of the input." << std::endl;
        return cities;
    }
    int size;
    try {
        size = std::stoi(line);
    } catch (const std::invalid_argument& ex) {
        std::cerr << "Invalid input size: " << line << std::endl;
        return cities;
    }

    // Read the city information from the file
    for (int i = 0; i < size; i++) {
        std::getline(file, line);
        std::istringstream ss(line);
        double latitude, longitude;
        std::string name;
        ss >> name >> latitude >> longitude;
        if (ss.fail()) {
            std::cerr << "Invalid input format in line " << i + 2 << std::endl;
            return cities;
        }
        cities.emplace_back(i, name, latitude, longitude);
    }

    file.close();
    return cities;
}
