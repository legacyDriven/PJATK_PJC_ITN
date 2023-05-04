//
// Created by Gienek on 29/04/2023.
//

#include <iostream>

bool isDigit(const char c) {
    return c >= '0' && c <= '9';
}

bool isUppercase(const char c) {
    return c >= 'A' && c <= 'Z';
}

bool isLowercase(const char c) {
    return c >= 'a' && c <= 'z';
}

bool isNonAlphanumeric(const char c) {
    return !isDigit(c) && !isUppercase(c) && !isLowercase(c);
}

bool checkpass(const char* pass) {
    int length = 0;
    int uniqueCharacters = 0;
    bool hasDigit = false;
    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasNonAlphanumeric = false;

    int occurrences[128] = {0};

    for (const char* c = pass; *c; ++c) {
        ++length;
        ++occurrences[*c];
        if (isDigit(*c)) hasDigit = true;
        if (isUppercase(*c)) hasUppercase = true;
        if (isLowercase(*c)) hasLowercase = true;
        if (isNonAlphanumeric(*c)) hasNonAlphanumeric = true;
    }

    for (int occurrence : occurrences) {
        if (occurrence) ++uniqueCharacters;
    }

    if (length < 8) {
        std::cout << "Too short" << std::endl;
    }
    if (uniqueCharacters < 6) {
        std::cout << "Too few different characters" << std::endl;
    }
    if (!hasDigit) {
        std::cout << "No digit" << std::endl;
    }
    if (!hasUppercase) {
        std::cout << "No uppercase letter" << std::endl;
    }
    if (!hasLowercase) {
        std::cout << "No lowercase letter" << std::endl;
    }
    if (!hasNonAlphanumeric) {
        std::cout << "No non-alphanumeric character" << std::endl;
    }

    return length >= 8 && uniqueCharacters >= 6
           && hasDigit && hasUppercase && hasLowercase && hasNonAlphanumeric;
}

int mainSix() {
    using std::cout; using std::endl;
    const char* passes[] =
            {
                    "AbcDe93",  "A1b:A1b>",  "Ab:Acb<",
                    "abc123><", "Zorro@123", nullptr
            };
    for (int i = 0; passes[i] != nullptr; ++i) {
        cout << "checking " << passes[i] << endl;
        if (checkpass(passes[i])) cout << "OK" << endl;
        cout << endl;
    }
}

