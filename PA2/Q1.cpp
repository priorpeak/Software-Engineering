#include <iostream>
#include <string>
#include <fstream>

#include "pa2Functions.h"

using namespace std;

int main() {
    // Print header
    initialize();

    while (command != 'q' || command != 'Q') {
        // Error check user input
        while (!checkCode(selectCommand())) {
            cout << "Invalid command code" << endl;
        }

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
            case 'Q' || 'q':
                return true;
            default:
                return false;
        }    
    }
    return 0;
}