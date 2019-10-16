#include <iostream>
#include <cmath>
#include <ctype.h>

#include "pa2Functions.h"

using namespace std;

// Function to print header
void initialize() {
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 2" << endl;
    cout << "Value of Entries is: " << ENTRIES << endl;
}

// Function to check that user input actually corresponds to a command code
bool checkCode(char command) {
    if (command == 'f' || command == 'b' || command == 'r' || command == 'u' || command == 'c' || command == 'e' || command == 'k' || command == 's' || command == 'n' || command == 'x' || command == 'l' || command == 'y' || command == 'd' || command == 'i' || command == 'o' || command == 'q') {
        return true;
    }
}

void writeDataToFile(const char *) {
    
}

void readDataFromFile(const char *) {

}

// Function to find the factorial of the given value
int factorial(int num1) {
    for (int i = 1; i <= num1; i++) {
        num1 *= i;
    }
    return num1;
}

// Function to find the fibonacci number at the given index
int fibonacci(int num1) {
    int fib[num1] = {1, 1};
    for (int i = 0; i <= num1; i++) {
        fib[i + 2] = fib[i + 1] + fib[i]
    }
    return fib[num1];
}

// Function to find the square root of a given value
double findSqrtValue(double num) {
    return sqrt(num);
}

// Function to ask for user input
char selectCommand() {
    while (isalpha(command)) {  //  Check that user input is a char
        cout << "Please enter command code: ";
        cin >> command;
    }
    command = tolower(command); //  Convert to lowercase for easier case matching

    return command;
}

// Check values in first, last, and delta
bool checkInput() {
    cout << "Please enter command parameters:" << endl;

    cout << "First: ";
    cin >> first;
    cout << "Last: ";
    cin >> last;
    cout << "Delta: ";
    cin >> delta;

    if (first > last || delta <= 0) {
        cout << "No computation needed." << endl;
        return false;
    }
    else {
        return true;
    }
}