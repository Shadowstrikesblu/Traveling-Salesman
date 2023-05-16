#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "City.h"
#include <cmath>
#include "Solution.h"



int main() {
    // open file
    std::ifstream file("../file.txt");
    // init city and line
    std::vector<City> cities;
    std::string line;
    // read first line
    if (!std::getline(file, line)) {
        std::cerr << "Failed to read the size of the input." << std::endl;
        return 1;
    }
    // convert line to int
    int size;
    try {
        size = std::stoi(line);
    } catch (const std::invalid_argument& ex) {
        std::cerr << "Invalid input size: " << line << std::endl;
        return 1;
    }
    double R = 6378.137;

    // check if file is open
    if (file.is_open()) {
        for (int i = 0; i < size; i++) {
            //read line per line
            std::getline(file, line);
            // split line into words
            std::istringstream ss(line);
            // init variables
            double latitude, longitude;
            std::string name;
            // read line into variables
            ss >> name >> latitude >> longitude;
            if (ss.fail()) {
                std::cerr << "Invalid input format in line " << i + 2 << std::endl;
                return 1;
            }
            // add city to vector
            cities.emplace_back(i, name, latitude, longitude);
        }
        // calculate average distance
        double totalDistance = 0.0;
        int count = 0;
        double last_long = Solution::convert(cities[-1].longitude);
        double last_lat = Solution::convert(cities[-1].latitude);
        double first_long = Solution::convert(cities[0].longitude);
        double first_lat = Solution::convert(cities[0].latitude);
        for (int i = 0; i < size - 1; i++) {
            double v_longitude = Solution::convert(cities[i].latitude);
            double v1_longitude = Solution::convert(cities[i + 1].latitude);
            double v_latitude = Solution::convert(cities[i].longitude);
            double v1_latitude = Solution::convert(cities[i + 1].longitude);

            double distance = R * acos(sin(v_latitude) * sin(v1_latitude) +
                                       cos(v_latitude) * cos(v1_latitude) *
                                       cos(v_longitude - v1_longitude));
//            std::cout << "Distance between cities " << i << " and " << i + 1 << ": " << distance << std::endl;
            totalDistance += distance;
            count++;
        }
        double last_distance = R * acos(sin(last_lat) * sin(first_lat) +
                            cos(last_lat) * cos(first_lat) *
                            cos(last_long - first_long));
        totalDistance+= last_distance;
        count +=1;
        double averageDistance = totalDistance / count ;
        std::cout << "Count: " << count  << std::endl;
        std::cout << "Average Distance: " << averageDistance << std::endl;
        std::ofstream MyFile;
        MyFile.open("../log.txt");
        MyFile << averageDistance;
        MyFile.close();
    } else {
        // throw error if file is not open
        std::cerr << "Failed to open file file.txt" << std::endl;
        return 1;
    }
    return 0;
}
