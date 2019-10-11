
// A simple version of the Google PageRank Algorithm
// Created by Kang Wang - A00992390 - October 11th, 2019

#include <iostream>
#include "matrix.hpp"
#include "operations.hpp"
#include <fstream>

int main() {
    // read file
    ifstream f("../input.txt");
    // vector to store doubles from file
    vector<double> inArr;
    // matrix input constructor
    matrix input;
    // matrix output constuctor
    matrix output;
    // constructing operation to perform operations on matrix
    operations op;
    // constructing input matrix
    if (!f.is_open()) { // Or if (!f) …
        cerr << "Unable to open file" << endl;
        exit(1);
    } else {
        double d;
        // store doubles in file into vector
        while(f >> d)
            inArr.push_back(d);
    }

    try {
        // put inArr values in input matrix
        matrix m(inArr);
        input = m;
    }
    catch (const char *) {
        cerr << "read-in vector size not in perfect root" << endl;
    }
    // divide each value in each column by the sum of each column.
    // last col, 1 / the number of pages
    op.importance(input);
    // M= 0.85 * S+ (1 -0.85) * Q, creating transition matrix
    op.transition(input);
    // Multiply the transition matrixMby our matrix rank
    output = op.markov(input);
    // finding the importance of each webpage in percent
    op.findPercent(output);
    // printing the web page in order of importance;
    op.print(output);
    return 0;
}