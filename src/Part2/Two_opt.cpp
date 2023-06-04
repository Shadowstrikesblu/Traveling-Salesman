//
// Created by hmoul on 03/06/2023.
//

#include <valarray>
#include "Two_opt.h"
//Reponse a la question 6.1
void Two_Opt(std::vector<int>& sequence, int i, int j) {
    int size = sequence.size();
    while (i < j) {
        std::swap(sequence[i], sequence[j]);
        i++;
        j--;
    }
}
//Reponse a la question 6.2
void Two_Opt_by_Index(std::vector<int>& sequence, int neighbourIndex){
    int n = (1 + sqrt(1+8 * neighbourIndex))/2;
    int i = neighbourIndex - (n * (n-1))/2;
    int j = sequence.size() - n + 1;
    return Two_Opt(sequence,i,j);
}