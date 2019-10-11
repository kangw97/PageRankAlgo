//
// Created by Kang on 10/5/2019.
//
#include <array>
#include "matrix.hpp"
// default constructor initializing 1 * 1 2d vevtor with value 0
matrix::matrix(): row{1}, col{1}{
    matri.resize(1, vector<double>(1, 0.0));
}
// constructing n * n vector with 0.0s
matrix::matrix(int n) {
    if(n <= 0)
        throw "n can't be 0 or negative";
    row = col = n;
    matri.resize(n, vector<double>(n, 0.0));
//    for (int i = 0; i < matri.size(); i++) {
//        for (int j = 0; j < matri[i].size(); j++)
//            cout << matri[i][j] << " ";
//        cout << endl;
//    }
}
// constructing r * c vector with 0.0s
matrix::matrix(int r, int c) {
    if(r <= 0)
        throw "row can't be 0 or negative";
    if(c <= 0)
        throw "col can't be 0 or negative";
    row = r;
    col = c;
    matri.resize(r, vector<double>(c, 0.0));
//    for (int i = 0; i < matri.size(); i++) {
//        for (int j = 0; j < matri[i].size(); j++)
//            cout << matri[i][j] << " ";
//        cout << endl;
//    }
}
// constructing a 2d vector that accept an double array
matrix::matrix(vector<double> doubleArr) {
    int size = doubleArr.size();
    double root = sqrt(doubleArr.size());
    if((root - floor(root)) != 0) {
        throw "array size not perfect square root";
    }
    matri.resize(root, vector<double>(root));
    row = col = root;
    for (int i = 0; i < matri.size(); i++) {
        for (int j = 0; j < matri[i].size(); j++)
            matri[i][j] = doubleArr[i*matri[i].size()+j];
    }
//    for (int i = 0; i < matri.size(); i++) {
//        for (int j = 0; j < matri[i].size(); j++)
//            cout << matri[i][j] << " ";
//        cout << endl;
//    }
}
// default destructor
matrix::~matrix() {
    cout << "Destructor\n";
}
// mutator for setting value on a specific location
void matrix::setValue(int r, int c, double n) {
    if(r < 0 || r >= this->row)
        throw "row not between 0 and vector row size";
    if(c < 0 || c >= this->col)
        throw "col not between 0 and vector col size";
    matri[r][c] = n;
}
// accessor for getting value on a specific location
double matrix::getValue(int r, int c) {
    if(r < 0 || r >= this->row)
        throw "row not between 0 and vector row size";
    if(c < 0 || c >= this->col)
        throw "col not between 0 and vector col size";
    return matri[r][c];
}
// setting all values to 0
void matrix::clear() {
    for (int i = 0; i < matri.size(); i++) {
        for (int j = 0; j < matri[i].size(); j++)
            matri[i][j] = 0.0;
    }
}
// overloading insertion
ostream& operator<<(ostream &os, const matrix &m) {
    for (int i = 0; i < m.matri.size(); i++) {
        for (int j = 0; j < m.matri[i].size(); j++)
            cout << m.matri[i][j] << " ";
        cout << endl;
    }
}
// overloading == operator
bool operator== (matrix const &m, matrix const &n) {
    if (m.matri.size() != n.matri.size() || m.matri[0].size() != n.matri[0].size())
        return false;
    for(int i = 0; i < n.matri.size(); i++){
        for(int j = 0; j < n.matri[i].size(); j++) {
            if(fabs(n.matri[i][j] - m.matri[i][j]) > numeric_limits<float>::epsilon())
                return false;
        }
    }
    return true;
}
// overloading != operator
bool operator!= (matrix const &m, matrix const &n) {
    return !operator==(m,n);
}
// mySwap function
void mySwap(matrix& first, matrix& second) {
    swap(first.matri, second.matri); //
}
// overloading += operator
void operator +=(matrix &m, matrix const &n) {
    if (m.matri.size() != n.matri.size() || m.matri[0].size() != n.matri[0].size())
        throw "matrix not same size";
    else {
        for(int i = 0; i < n.matri.size(); i++){
            for(int j = 0; j < n.matri[i].size(); j++) {
                m.matri[i][j] += n.matri[i][j];
            }
        }
    }
}
// overloading + operator
matrix operator +(matrix const &m, matrix const &n) {
    if (m.matri.size() != n.matri.size() || m.matri[0].size() != n.matri[0].size())
        throw "matrix not same size";
    else {
        matrix dm(n.matri.size(),n.matri[0].size());
        for(int i = 0; i < n.matri.size(); i++){
            for(int j = 0; j < n.matri[i].size(); j++) {
                dm.matri[i][j] = m.matri[i][j] + n.matri[i][j];
            }
        }
        return dm;
    }
}
// overloading += operator
void operator -=(matrix &m, matrix const &n) {
    if (m.matri.size() != n.matri.size() || m.matri[0].size() != n.matri[0].size())
        throw "matrix not same size";
    else {
        for(int i = 0; i < n.matri.size(); i++){
            for(int j = 0; j < n.matri[i].size(); j++) {
                m.matri[i][j] -= n.matri[i][j];
            }
        }
    }
}
// overloading + operator
matrix operator -(matrix const &m, matrix const &n) {
    if (m.matri.size() != n.matri.size() || m.matri[0].size() != n.matri[0].size())
        throw "matrix not same size";
    else {
        matrix dm(n.matri.size(),n.matri[0].size());
        for(int i = 0; i < n.matri.size(); i++){
            for(int j = 0; j < n.matri[i].size(); j++) {
                dm.matri[i][j] = m.matri[i][j] - n.matri[i][j];
            }
        }
        return dm;
    }
}
// overloading * operator
matrix operator *(matrix const &m, matrix const &n) {
    if(m.matri[0].size() != n.matri.size())
        throw "matrix can not multiply";
    else {
        matrix dm(m.matri.size(),n.matri[0].size());
        for(int i = 0; i < m.matri.size(); i++){
            for(int j = 0; j < n.matri[0].size(); j++) {
                dm.matri[i][j] = 0;
                for (int k = 0; k < n.matri.size(); k++){
                    dm.matri[i][j] += m.matri[i][k] * n.matri[k][j];
                }
            }
        }
        return dm;
    }
}
// overloading *= operator
void operator *=(matrix &m, matrix const &n) {
    if(m.matri[0].size() != n.matri.size())
        throw "matrix can not multiply";
    else
        m = m * n;
}