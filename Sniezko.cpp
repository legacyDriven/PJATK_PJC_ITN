//
// Created by Gienek on 26/03/2023.
//

#include <iostream>
#include <utility>

void ord3(double& a, double& b, double& c) {
    if (a > b) std::swap(a, b);
    if (b > c) std::swap(b, c);
    if (a > b) std::swap(a, b);
}

void ord3(double* a, double* b, double* c) {
    ord3(*a, *b, *c);
}

void getMinMax(const double &a, const double& b, const double& c, const double*& pMin, const double*& pMax) {
    pMin = &a;
    pMax = &a;

    if (b < *pMin) pMin = &b;
    if (c < *pMin) pMin = &c;

    if (b > *pMax) pMax = &b;
    if (c > *pMax) pMax = &c;
}

void getMinMax(const double *a, const double* b, const double* c, const double** pMin, const double** pMax) {
    getMinMax(*a, *b, *c, *pMin, *pMax);
}

void printOrd(const double* a, const double* b, const double* c) {
    using std::cout;
    using std::endl;
    cout << *a << " " << *b << " " << *c << endl;
}

