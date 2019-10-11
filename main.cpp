
// A simple version of the Google PageRank Algorithm
// Created by Kang Wang - A00992390 October 5th, 2019
#include <iostream>
#include "matrix.hpp"

int main() {
    vector<double> arr = {12.0, 1.3, 6.2, 4.3,12.0, 1.3, 6.2, 4.3,12.0, 1.3, 6.2, 4.3,12.0, 1.3, 6.2, 4.3};
    vector<double> krr= {12.0, 1.3, 6.2, 4.3};
    try {
        matrix m(1, 1);
        m.setValue(0, 0, 10);
        matrix n(1, 2);
        n.setValue(0, 0, 10);
        n.setValue(0, 1, 10);
        m*=n;
        cout << m;

    } catch (char const*){
        cout << "Invalid Argument" << endl;
    }
    return 0;
}