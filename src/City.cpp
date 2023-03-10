//
// Created by louis on 14/02/23.
//

#include "City.h"
#include <cmath>

City::City(std::string name, double latitude, double longitude) :
        name(name), latitude(latitude), longitude(longitude) {}

double City::distance(City other_city) {
    double earth_radius = 6371; // km
    double d_latitude = M_PI/180 * (other_city.latitude - latitude);
    double d_longitude = M_PI/180 * (other_city.longitude - longitude);
    double a = std::sin(d_latitude/2) * std::sin(d_latitude/2) +
               std::cos(M_PI/180 * latitude) * std::cos(M_PI/180 * other_city.latitude) *
               std::sin(d_longitude/2) * std::sin(d_longitude/2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1-a));
    double distance = earth_radius * c;
    return distance;
}