//
// Created by Gienek on 15/03/2023.
//
#include <iostream>
#include <limits>

void printResult(int minValue, int maxValue, int minCounter, int maxCounter){
    std::cout << "Min = " << minValue << " " << minCounter << " razy" << std::endl;
    std::cout << "Max = " << maxValue << " " << maxCounter << " razy" << std::endl;
}

int mainRenameToRun() {

    int entry;
    int minValue;
    int maxValue;
    int minCounter = 0;
    int maxCounter = 0;

    minValue = std::numeric_limits<int>::max();
    maxValue = std::numeric_limits<int>::min();

    std::cout << "Please enter integer sequence, " <<
                 "entering zero value will terminate process and produce result:" << std::endl;

    while (std::cin >> entry && entry != 0) {
        if (entry < minValue) {
            minValue = entry;
            minCounter = 1;
        } else if (entry == minValue) {
            minCounter++;
        }

        if (entry > maxValue) {
            maxValue = entry;
            maxCounter = 1;
        } else if (entry == maxValue) {
            maxCounter++;
        }
    }

    printResult(minValue, maxValue, minCounter, maxCounter);

    return 0;
}

