//
// Created by louis on 14/02/23.
//

#ifndef TRAVELING_SALESMAN_SOLUTION_H
#define TRAVELING_SALESMAN_SOLUTION_H


#include <vector>
#include "Instance.h"

class Solution {
public:
    Solution(Instance &instance);
    double evaluate();
    void randomize();
    void print();
    void write(std::string filename);
    void read(std::string filename);
private:
    Instance &instance;
    std::vector<City> sequence;
    double total_distance;
};

#endif