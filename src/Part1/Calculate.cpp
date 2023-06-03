//
// Created by hmoul on 20/05/2023.
//

#include <vector>
#include "Calculate.h"
#include "../City.h"
#include "Solution.h"
#include <cmath>
#include <iostream>

double CalculateDistance(const City& city1, const City& city2) {
    double R = 6378.137;
    double v_longitude = Solution::convert(city1.latitude);
    double v1_longitude = Solution::convert(city2.latitude);
    double v_latitude = Solution::convert(city1.longitude);
    double v1_latitude = Solution::convert(city2.longitude);
    double result =  R * acos(sin(v_latitude) * sin(v1_latitude) +
                    cos(v_latitude) * cos(v1_latitude) *
                    cos(v_longitude - v1_longitude));
    return result;

}

double Calculate(const std::vector<City>& cities) {
    double totalDistance = 0.0;
    int count = 0;

    for (int i = 0; i < cities.size() - 1; i++) {
        double distance = CalculateDistance(cities[i], cities[i + 1]);
        std::cout << "Distance entre les villes " << i << " et " << i + 1 << ": " << distance << std::endl;
        totalDistance += distance;
        count++;
    }

    double averageDistance = totalDistance / count;
    std::cout << "Distance moyenne: " << averageDistance << std::endl;
}
