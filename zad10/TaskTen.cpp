//
// Created by Gienek on 29/06/2023.
//
#include <iostream>
#include <cstring>

class Person {
    char* name;
    friend class Couple;
public:
    explicit Person(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    Person(const Person& os) {
        name = new char[strlen(os.name) + 1];
        strcpy(name, os.name);
    }

    Person& operator=(const Person& os) {
        if (this != &os) {
            delete[] name;
            name = new char[strlen(os.name) + 1];
            strcpy(name, os.name);
        }
        return *this;
    }

    ~Person() {
        std::cout << "DEL " << name << std::endl;
        delete[] name;
    }

    friend std::ostream& operator<<(std::ostream& str, const Person& os) {
        return str << os.name;
    }
};

class Couple {
    Person *wife, *husband;
public:
    Couple(const Person& she, const Person& he) {
        wife = new Person(she);
        husband = new Person(he);
    }

    Couple(const Couple& other) {
        wife = new Person(*other.wife);
        husband = new Person(*other.husband);
    }

    Couple& operator=(const Couple& other) {
        if (this != &other) {
            delete wife;
            delete husband;
            wife = new Person(*other.wife);
            husband = new Person(*other.husband);
        }
        return *this;
    }

    ~Couple() {
        delete wife;
        delete husband;
    }

    friend std::ostream& operator<<(std::ostream& str, const Couple& c) {
        return str << "Couple: he " << *c.husband << ", she " << *c.wife;
    }
};

int mainTen(void) {
    using std::cout; using std::endl;
    Person *pjohn = new Person("John"),
            *pjane = new Person("Jane");
    Person mary("Mary"), mark("Mark");
    Couple *pcouple1 = new Couple(mary, *pjohn);
    Couple couple2(*pjane, mark);
    delete pjohn;
    delete pjane;
    cout << *pcouple1 << endl;
    cout << couple2 << endl;
    couple2 = *pcouple1;
    delete pcouple1;
    cout << couple2 << endl;
}
