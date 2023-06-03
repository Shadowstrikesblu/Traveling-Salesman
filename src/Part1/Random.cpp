//
// Created by hmoul on 19/05/2023.
//

#include <vector>
#include <random>
#include "Random.h"
#include "../City.h"


void RandomizeCityOrder(std::vector<City>& cities){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(cities.begin(), cities.end(), gen);
}