#include <iostream>
#include <cmath>
#include "pa2Functions.h"

using namespace std;

extern const int ENTRIES;

void initialize() {
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 2" << endl;
    cout << "Value of Entries is: " << ENTRIES << endl;
}

bool checkCode(char command) {
    switch (command) {
        case 'f' || 'F':
            return true;
        case 'B' || 'b':
            return true;
        case 'R' || 'r':
            return true;
        case 'U' || 'u':
            return true;
        case 'C' || 'c':
            return true;
        case 'E' || 'e':
            return true;
        case 'K' || 'k':
            return true;
        case 'S' || 's':
            return true;
        case 'N' || 'n':
            return true;
        case 'X' || 'x':
            return true;
        case 'L' || 'l':
            return true;
        case 'Y' || 'y':
            return true;
        case 'D' || 'd':
            return true;
        case 'I' || 'i':
            return true;
        case 'O' || 'o':
            return true;
        case 'Q' || 'q':
            return true;
        default:
            return false;
    }
}

void writeDataToFile(const char *) {
    
}