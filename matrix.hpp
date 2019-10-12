//
// Created by Kang Wang on 10/5/2019.
// setting up matrix operations
//
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
using namespace std;
#ifndef PAGERANKALGO_MATRIX_HPP
#define PAGERANKALGO_MATRIX_HPP
// typedef double 2d vector
typedef vector<vector<double> > doubleMatrix;
class matrix {
private:
    doubleMatrix matri;
    int row, col;
public:
    // default constructor
    matrix();
    // constructing n * n vector with 0.0s
    matrix(int n);
    // constructing r * c vector with 0.0s
    matrix(int r, int c);
    // constructing a 2d vector that accept an double array
    matrix(vector<double>);
    // default destructor
    ~matrix();
    // accessors for row and col
    inline int getRow() const{ return row;}
    inline int getCol() const { return col; }
    // mutator for setting value on a specific location
    void setValue(int r, int c, double n);
    // accessor for getting value on a specific location
    double getValue (int r, int c) const;
    // setting all values to 0
    void clear();
    // overloading insertion
    friend ostream& operator<<(ostream &os, matrix const &m);
    // overloading == operator
    friend bool operator ==(matrix const &m, matrix const &n);
    // overloading != operator
    friend bool operator !=(matrix const &m, matrix const &n);
    // overloading prefix ++
    void operator++() {
        for(int i = 0; i < matri.size(); i++)
            for(int j = 0; j < matri[i].size(); j++)
                ++matri[i][j];

    }
    // overloading postfix ++
   void operator++(int) {
        for(int i = 0; i < matri.size(); i++)
            for(int j = 0; j < matri[i].size(); j++)
                matri[i][j]++;
    }
    // overloading prefix --
    void operator--() {
        for(int i = 0; i < matri.size(); i++)
            for(int j = 0; j < matri[i].size(); j++)
                --matri[i][j];
    }
    // overloading postfix --
    void operator--(int) {
        for (int i = 0; i < matri.size(); i++)
            for (int j = 0; j < matri[i].size(); j++)
                matri[i][j]--;
    }
    // overloading = operator
    matrix& operator=(matrix rhs) {
        mySwap(*this, rhs);
        return *this;
    }
    // friend mySwap
    friend void mySwap(matrix& first, matrix& second);
    // overloading += operator
    friend void operator +=(matrix &m, matrix const &n);
    // overloading + operator
    friend matrix operator +(matrix const &m, matrix const &n);
    // overloading -= operator
    friend void operator -=(matrix &m, matrix const &n);
    // overloading - operator
    friend matrix operator -(matrix const &m, matrix const &n);
    // overloading * operator
    friend matrix operator *(matrix const &m, matrix const &n);
    // overloading *= operator
    friend void operator *=(matrix &m, matrix const &n);
};
#endif //PAGERANKALGO_MATRIX_HPP
