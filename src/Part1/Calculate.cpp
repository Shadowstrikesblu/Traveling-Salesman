//
// Created by hmoul on 20/05/2023.
//

#include <vector>
#include "Calculate.h"
#include "../City.h"
#include "Solution.h"
#include <cmath>
#include <iostream>

void Calculate(const std::vector<City>& cities) {
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
}