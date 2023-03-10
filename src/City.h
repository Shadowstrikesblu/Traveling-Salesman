//
// Created by louis on 14/02/23.
//

#ifndef TRAVELING_SALESMAN_CITY_H
#define TRAVELING_SALESMAN_CITY_H

#include <string>

class City {
public:
    City(std::string name, double latitude, double longitude);
    double distance(City other_city);
    std::string name;
    double latitude;
    double longitude;
};

#endif
