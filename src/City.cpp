#include "City.h"
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

City::City(int id, std::string name, double latitude, double longitude) :
        id(id), name(name), latitude(latitude), longitude(longitude) {}

double City::distance(const City& other_city) const {
    double earth_radius = 6378.137;
    double d_latitude = M_PI / 180 * (other_city.latitude - latitude);
    double d_longitude = M_PI / 180 * (other_city.longitude - longitude);
    double a = std::sin(d_latitude / 2) * std::sin(d_latitude / 2) +
               std::cos(M_PI / 180 * latitude) * std::cos(M_PI / 180 * other_city.latitude) *
               std::sin(d_longitude / 2) * std::sin(d_longitude / 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    double distance = earth_radius * c;
    return distance;
}


