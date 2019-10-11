//
// Created by Kang Wang on 10/11/2019.
// To perform required functions for matrix to find the ranking of web pages
//
#include "matrix.hpp"
#include "iomanip"
#ifndef PAGERANKALGO_OPERATIONS_HPP
#define PAGERANKALGO_OPERATIONS_HPP

class operations: public matrix {
public:
    // divide each value in each column by the sum of each column.
    // last col, 1 / the number of pages
    void importance(matrix& m);
    // M= 0.85 * S+ (1 -0.85) * Q, creating transition matrix
    void transition(matrix& m);
    // Multiply the transition matrixMby our matrixrank
    matrix markov(matrix& m);
    // finding the importance of each webpage in percent
    void findPercent(matrix& m);
    // printing the web page in order of importance;
    void print(matrix& m);
};
#endif //PAGERANKALGO_OPERATIONS_HPP
