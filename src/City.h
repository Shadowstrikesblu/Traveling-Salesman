//
// Created by louis on 14/02/23.
//

#ifndef TRAVELING_SALESMAN_CITY_H
#define TRAVELING_SALESMAN_CITY_H

#include <string>

class City {
public:
    City(int id, std::string name, double latitude, double longitude);
    double distance(City other_city);
    int id;
    std::string name;
    double latitude;
    double longitude;


    double distance(const City &other_city) const;

    void readTSPFile(const std::string &filename);
};


#endif
