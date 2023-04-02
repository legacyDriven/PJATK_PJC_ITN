//
// Created by Gienek on 20/03/2023.
//
#include <iostream>

#if defined(POL) && defined(ENG)
#error "Define only one of the macros: POL or ENG"
#elif !defined(POL) && !defined(ENG)
#error "Define one of the macros: POL or ENG"
#endif

int sumOfDigits(int entry) {
    int result = 0;
    while (entry > 0) {
        result += entry % 10;
        entry /= 10;
    }
    return result;
}

int mainTwo() {
    int number;
    int maxSum = -1;
    int maxNumber;

    while (true) {
#ifdef POL
        std::cout << "Wprowadz liczne naturalna, 0 by zakonczyc: ";
#elif defined(ENG)
        std::cout << "Enter a natural number, 0 if done: ";
#endif

        std::cin >> number;

        if (number == 0) break;

        int current_sum = sumOfDigits(number);
        if (current_sum > maxSum) {
            maxSum = current_sum;
            maxNumber = number;
        }
    }

#ifdef POL
    std::cout << "Najwieksza suma cyfr wynosi " << maxSum << " dla liczby " << maxNumber << std::endl;
#elif defined(ENG)
    std::cout << "Max sum of digits was " << maxSum << " for " << maxNumber << std::endl;
#endif

    return 0;
}
