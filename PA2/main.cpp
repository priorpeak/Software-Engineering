#include <iostream>
#include <cmath>

#include "pa2Functions.h"

using namespace std;

int num1, num2, counter = 0;
const int ENTRIES = 10;
double first, last, delta = 0;
char command;

int main() {
    // Print header
    initialize();

    do {
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
                cout << endl << endl;
                break;
            case 'b':
                cout << "Please enter a number: ";
                cin >> num1;
                num2 = fibonacci(num1);
                cout << "The Fibonacci number at index " << num1 << " is " << num2 << endl;
                cout << endl << endl;
                break;
            case 'r':
                if (checkInput()) {
                    cout << endl << endl;
                    if (first + delta > last) {
                        cout << findSqrtValue(first) << endl;
                        cout << findSqrtValue(last) << endl;
                } else {
                    for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                        cout << findSqrtValue(i) << endl;
                        counter++;
                    }
                }
                counter = 0;
                }
                cout << endl << endl;
                break;
            case 'u':
                if (checkInput()) {
                    cout << endl << endl;
                    if (first + delta > last) {
                        cout << areaSquare(first) << endl;
                        cout << areaSquare(last) << endl;
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << areaSquare(i) << endl;
                            counter++;
                        }
                    }
                counter = 0;
                }
                cout << endl << endl;
                break;
            case 'c':
                if (checkInput()) {
                    cout << endl << endl;
                    if (first + delta > last) {
                        cout << areaCircle(first) << endl;
                        cout << areaCircle(last) << endl;
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << areaCircle(i) << endl;
                            counter ++;
                        }
                    }
                counter = 0;
                }
                cout << endl << endl;
                break;
            case 'e':
                if (checkInput()) {
                    cout << endl << endl;
                    for (int i = first; i <= last && counter <= ENTRIES; i++) {
                        if (findNextEvenValue(i) != 1) {
                            cout << findNextEvenValue(i) << endl;
                            counter++;
                        }
                    }
                counter = 0;
                }
                cout << endl << endl;
                break;
            case 'k':
                if (checkInput()) {
                    cout << endl << endl;
                    if (first + delta > last) {
                        cout << lucky(first) << endl;
                        cout << lucky(last) << endl;
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << lucky(i) << endl;
                            counter ++;
                        }
                    }
                counter = 0;
                }
                cout << endl << endl;
                break;
            case 's':
                if (checkInput()) {
                    cout << endl << endl;
                    if (first + delta > last) {
                        cout << doMath(first, 's') << endl;
                        cout << doMath(last, 's') << endl;
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << doMath(i, 's') << endl;
                            counter ++;
                        }
                    }
                counter = 0;
                }
                cout << endl << endl;
                break;
            case 'n':
                if (checkInput()) {
                    cout << endl << endl;
                    if (first + delta > last) {
                        cout << doMath(first, 'n') << endl;
                        cout << doMath(last, 'n') << endl;
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << doMath(i, 'n') << endl;
                            counter ++;
                        }
                    }
                counter = 0;
                }
                cout << endl << endl;
                break;
            case 'x':
                if (checkInput()) {
                    cout << endl << endl;
                    if (first + delta > last) {
                        cout << doMath(first, 'x') << endl;
                        cout << doMath(last, 'x') << endl;
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << doMath(i, 'x') << endl;
                            counter ++;
                        }
                    }
                counter = 0;
                }
                cout << endl << endl;
                break;
            case 'l':
                if (checkInput()) {
                    cout << endl << endl;
                    if (first + delta > last) {
                        cout << naturalLog(first) << endl;
                        cout << naturalLog(last) << endl;
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << naturalLog(i) << endl;
                            counter ++;
                        }
                    }
                counter = 0;
                }
                cout << endl << endl;
                break;
            case 'y':
                if (checkInput()) {
                    cout << endl << endl;
                    if (first + delta > last) {
                        cout << findNyanCatValue(first) << endl;
                        cout << findNyanCatValue(last) << endl;
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << findNyanCatValue(i) << endl;
                            counter ++;
                        }
                    }
                counter = 0;
                }
                cout << endl << endl;
                break;
            case 'd':
                if (checkInput()) {
                    cout << endl << endl;
                    for (int i = first; i <= last && counter <= ENTRIES; i++) {
                        if (findNextOddValue(i) != 0) {
                            cout << findNextOddValue(i) << endl;
                            counter++;
                        }
                    }
                counter = 0;
                }
                cout << endl << endl;
                break;
        }
    } while (command != 'q' || command != 'Q');  

    cout << "Program exiting" << endl;

    return 0;
}