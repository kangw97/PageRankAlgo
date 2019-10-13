//
// Created by Kang Wang on 10/11/2019.
// To perform required functions for matrix to find the ranking of web pages
//

#include "operations.hpp"
// divide each value in each column by the sum of each column.
// last col, 1 / the number of pages
void operations::importance(matrix &m) {
    try {
        for (int i = 0; i < m.getCol(); i++) {
            int div = 0;
            for (int j = 0; j < m.getRow(); j++) {
                div += m.getValue(j, i);
            }
            for (int j = 0; j < m.getRow(); j++) {
                if (div != 0)
                    m.setValue(j, i, m.getValue(j, i) / div);
                else
                    m.setValue(j, i, 1.0 / m.getCol());
            }
        }
    } catch (const char*) {
        cerr << "index out of bound\n";
    }
}
// M= 0.85 * S+ (1 -0.85) * Q, creating transition matrix
void operations::transition(matrix& m) {
    matrix trans(m.getCol());
    matrix prob1(m.getCol());
    matrix prob2(m.getCol());
    try {
        for (int i = 0; i < m.getRow(); i++) {
            for (int j = 0; j < m.getRow(); j++) {
                trans.setValue(i, j, 1.0 / m.getCol());
                if (i == j) {
                    prob1.setValue(i, j, 0.85);
                    prob2.setValue(i, j, 0.15);
                }
            }
        }
    } catch (const char*) {
        cerr << "index out of bound\n";
    }
    try {
        m = prob1 * m + prob2 * trans;
    } catch (const char*) {
        cerr << "matrix can not multiply, and add\n";
    }
}
// Multiply the transition matrixMby our matrixrank
matrix operations::markov(matrix const &m) {
    matrix rank(m.getCol(), 1);
    matrix result1(m.getCol(), 1);
    matrix result2(m.getCol(), 1);
    try {
        for (int i = 0; i < m.getCol(); i++)
            rank.setValue(i, 0, 1);
    } catch (const char*) {
        cerr << "index out of bound\n";
    }
    try {
        result1 = m * rank;
        while (result2 != result1) {
            result2 = result1;
            result1 = m * result2;
        }
    } catch (const char*) {
        cerr << "matrix can not multiply, and add\n";
    }
    return result2;
}
// finding the importance of each webpage in percent
void operations::findPercent(matrix& m) {
    double sum = 0;
    try {
        for (int i = 0; i < m.getRow(); i++)
            sum += m.getValue(i, 0);
        for (int i = 0; i < m.getRow(); i++)
            m.setValue(i, 0, m.getValue(i, 0) / sum);
    } catch (const char*) {
        cerr << "index out of bound\n";
    }
}
// printing the web page in order of importance;
void operations::print (matrix const &m) const {
    char page = 'A';
    try {
        // printing and formatting
        for (int i = 0; i < m.getRow(); i++)
            cout << "Page " << page++ << ": " << fixed << setprecision(2) << setw(5) << m.getValue(i, 0) * 100 << "%"
                 << endl;
    } catch (const char*) {
        cerr << "index out of bound\n";
    }
}