//
// Created by Gienek on 01/04/2023.
//
#include <iostream>
#include <utility>
using std::swap;

void getMinMax(const double &a, const double& b,
               const double& c,
               const double*& pMin, const double*& pMax) {
    pMin = &a;
    pMax = &a;
    if (b < *pMin) {
        pMin = &b;
    } else if (b > *pMax) {
        pMax = &b;
    }
    if (c < *pMin) {
        pMin = &c;
    } else if (c > *pMax) {
        pMax = &c;
    }
}

void getMinMax(const double *a, const double* b,
               const double* c,
               const double** pMin, const double** pMax) {
    *pMin = a;
    *pMax = a;
    if (*b < **pMin) {
        *pMin = b;
    } else if (*b > **pMax) {
        *pMax = b;
    }
    if (*c < **pMin) {
        *pMin = c;
    } else if (*c > **pMax) {
        *pMax = c;
    }
}

void ord3(double& a, double& b, double& c) {
    if(a > b) swap (a,b);
    if(a > c) swap (a,c);
    if(b > c) swap (b,c);
}

void ord3(double* a, double* b, double* c) {
    if(*a > *b) swap(*a, *b);
    if(*a > *c) swap(*a, *c);
    if(*b > *c) swap(*b, *c);
}

void printOrd(const double* a, const double* b,
              const double* c) {
    using std::cout; using std::endl;
    cout << *a << " " << *b << " " << *c << endl;
}
void printMinMax(const double* pmn, const double* pmx) {
    using std::cout; using std::endl;
    std:: cout << "Min = " << *pmn << "; "
               << "Max = " << *pmx << std::endl;
}

int mainThree() {
    double a, b, c;
    const double *pMin, *pMax;
    a = 2; b = 1; c = 3;
    ord3(a,b,c);
    printOrd(&a, &b, &c);
    a = 3; b = 2; c = 1;
    ord3(&a,&b,&c);
    printOrd(&a, &b, &c);
    a = -1; b = -1; c = 1;
    ord3(&a,&b,&c);
    printOrd(&a, &b, &c);
    a = 2; b = 3; c = 1;
    getMinMax(a,b,c,pMin,pMax);
    printMinMax(pMin, pMax);
    a = 3; b = 1; c = 2;
    getMinMax(&a,&b,&c,&pMin,&pMax);
    printMinMax(pMin, pMax);
    a = 3; b = 3; c = -1;
    getMinMax(&a,&b,&c,&pMin,&pMax);
    printMinMax(pMin, pMax);
}


