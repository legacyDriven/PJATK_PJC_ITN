//
// Created by Gienek on 08/04/2023.
//
#include <iostream>

int gcdRec(int a, int b);
int sumDigits(int n);
int numDigits(int n);
void printOddEven(int n);
void printEven(int n);
void printOdd(int n);
void hailstone(int n);

int gcdRec(int a, int b){
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else if (a == b)
        return a;
    else if (a > b)
        return gcdRec(a % b, b);
    else
    return gcdRec(b % a, a);
}

int sumDigits(int n){
    return n == 0 ? 0 : (n % 10) + sumDigits(n / 10);
}

int numDigits(int n){
    return n == 0 ? 0 : 1 + numDigits(n / 10);
}


void printOddEven(int n) {
    if (n == 0)
        return;
    if(n % 2 == 0)
        printEven(n);
    else
        printOdd(n);
}

void printOdd(int n) {
    if (n < 1) {
        return;
    }
    if (n % 2 == 0) {
        n -= 1;
    }
    printOdd(n - 2);
    std::cout << n << " ";
}

void printEven(int n) {
    if (n < 2) {
        return;
    }
    if (n % 2 == 1) {
        n -= 1;
    }
    printEven(n - 2);
    std::cout << n << " ";
}


void hailstone(int n) {
    std::cout << n << " ";
    if (n == 1) {
        return;
    }
    if (n % 2 == 0) {
        hailstone(n / 2);
    } else {
        hailstone(3 * n + 1);
    }
}


int mainFive() {
    std::cout << "gcdRec(12, 42) = " <<
              gcdRec(12, 42) << std::endl
              << "gcdRec(12, 25) = " <<
              gcdRec(12, 25) << std::endl;
    std::cout << "sumDigits(123) = " <<
              sumDigits(123) << std::endl
              << "sumDigits(971) = " <<
              sumDigits(971) << std::endl;
    std::cout << "numDigits(12345) = " <<
              numDigits(12345) << std::endl
              << "numDigits(971) = " <<
              numDigits(971) << std::endl;
    std::cout << "printOddEven(15): ";
    printOddEven(15);
    std::cout << std::endl;
    std::cout << "printOddEven(14): ";
    printOddEven(14);
    std::cout << std::endl;
    std::cout << "hailstone(13): ";
    hailstone(13);
    std::cout << std::endl;
}
