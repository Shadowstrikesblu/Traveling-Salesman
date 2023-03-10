

#include <fstream>
#include <iostream>
#include <vector>
#include "City.h"

int main() {
// read all file, print the content of the file.txt and throw error if read not possible
    std::ifstream file("../file.txt");
    double total_distance;
    file >> total_distance;
    std::string line;
    if (file.is_open()) {
        std::vector<City> new_sequence;
        while (std::getline(file, line)) {
        std::cout << line << std::endl;
        }
    } else {
        throw std::runtime_error("Cannot open file file.txt");
    }
}

