#include <iostream>

#include "pa2Functions.h"

using namespace std;

extern const int ENTRIES;
char command;
double first, last, delta;
int num1, num2;

int main() {
    // Print header
    initialize();

    while (command != 'q' || command != 'Q') {
        // Error check user input
        while (!checkCode(selectCommand())) {
            cout << "Invalid command code" << endl;
        }

        // Match user input with relevant function in pa2Functions.h
        switch (command) {
            case 'f':
                cout << "Please enter a number to return the factorial: ";
                cin >> num1;
                num2 = factorial(num1);
                cout << "The factorial of "<< num1 << " is " << num2 << endl;
                break;
            case 'b':
                cout << "Please enter a number: ";
                cin >> num1;
                num2 = fibonacci(num1);
                cout << "The Fibonacci number at index " << num1 << " is " << num2 << endl;
                break;
            case 'r':
                if (checkInput()) {
                    if (first + delta > last) {
                        cout << findSqrtValue(first) << endl;
                        cout << findSqrtValue(last) << endl;
                } else {
                    for (int i = first; i < last && ENTRIES >= 0; i += delta) {
                        cout << findSqrtValue(i) << endl;
                    }
                }
                }
                break;
            case 'u':
                
        }   
    return 0;
}