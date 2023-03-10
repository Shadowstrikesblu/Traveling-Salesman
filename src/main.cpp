

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "City.h"

int main() {
    // open file
    std::ifstream file("../file.txt");
    // init city and line
    std::vector<City> city;
    std::string line;
    // read first line
    std::getline(file, line);
    // convert line to int
    int size = std::stoi(line);
    // check if file is open
    if (file.is_open()) {
        for (int i = 0; i < size; i++) {
            //read line per line
            std::getline(file, line);
            // write line to console
            std::cout << line << std::endl;
            // split line into words
            std::istringstream ss(line);
            // init variables
            double latitude, longitude;
            std::string name;
            // read line into variables
            ss >> name >> latitude >> longitude;
            // add city to vector
            city.emplace_back(i, name, latitude, longitude);
        }
    } else {
        // throw error if file is not open
        throw std::runtime_error("Cannot open file file.txt");
    }
}