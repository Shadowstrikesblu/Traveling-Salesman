//
// Created by hmoul on 20/05/2023.
//

#include <vector>
#include <iostream>
#include "Print.h"
#include "../City.h"

void Print(const std::vector<City>& cities) {
//    std::cout << "Solution:" << std::endl;
    for (const City& city : cities) {
        std::cout << city.id << std::endl;
    }
}