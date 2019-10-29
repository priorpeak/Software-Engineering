#include <iostream>
#include <cmath>
#include <ctype.h>
#include <time.h>
#include <fstream>
#include <string.h>

#include "pa2Functions.h"

#define PI 3.141592653589793238462643383279502884197169399

using namespace std;
extern ofstream writeFile;
extern ifstream input;
string line2;

// Function to print header
void initialize() {
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 2" << endl;
    cout << "Value of Entries is: " << ENTRIES << endl;
    return;
}

// Function to check that user input actually corresponds to a command code
bool checkCode(char command) {
    if (command == 'f' || command == 'b' || command == 'r' || command == 'u' || command == 'c' || command == 'e' || command == 'k' || command == 's' || command == 'n' || command == 'x' || command == 'l' || command == 'y' || command == 'd' || command == 'i' || command == 'o' || command == 'q') {
        return true;
    }
}

// This function opens a file (name gotten from user input) for output to be written to
void writeDataToFile(const char *charArray) {
    writeFile.open(charArray);
    return;
}

// This function takes input from a text file and performs functions based off that input
void readDataFromFile(const char *charArray2) {
    input.open(charArray2);
    return;
}

// Function to find the factorial of the given value
int factorial(int num1) {
    int limit = num1;
    for (int i = 1; i < limit; i++) {
        num1 *= i;
    }
    return num1;
}

// Function to find the fibonacci number at the given index
int fibonacci(int num1) {
    int fib[64000] = {0, 1};
    int i;
    for (i = 0; i <= num1; i++) {
        fib[i + 2] = fib[i + 1] + fib[i];
    }
    return fib[i - 2];
}

// Function to find the square root of a given value
double findSqrtValue(double num) {
    return sqrt(num);
}

// Function to return the logarithm given a range of numbers
double naturalLog(double num) {
    return log(num);
}

// Function to find the area of a circle given a radius
double areaCircle(double radius) {
    double area = 0;
    return area = PI * pow(radius, 2);
}

// Function to find the area of a square given a side length
double areaSquare(double num) {
    return pow(num, 2);
}

// Function to only return odd values given a range of numbers
int findNextOddValue(int num) {
    if (num % 2 != 0) {
        return num;
    } else {
        return 0;
    }
}

// Function to only return even values given a range of numbers
int findNextEvenValue(int num) {
    if (num % 2 == 0) {
        return num;
    } else {
        return 1;
    }
}

// Function to return the "Nyan Cat Value" given a range of numbers
double findNyanCatValue(double num) {
    return pow(4 * num, num) + num + 10;
}

// Function to compute sin, cosine, and exponential values given a range of numbers
double doMath(double num, char op) {
    switch (op) {
        case 's':
            return sin(num);
            break;
        case 'n':
            return cos(num);
            break;
        case 'x':
            return exp(num);
            break;
    }
}

// Function to return a random number based off system time
double lucky(double num) {
    time_t timer;
    double current_time = time(&timer);
    return (num * current_time);
}


// Function to ask for user input
char selectCommand() {
    if (input.is_open()) {
        getline(input, line2);
        command = tolower(*line2.c_str()); // Convert to a char and lowercase for easier case matching
        if (input.eof()) {
            input.close();
            fileIn = false;
        }

        return command;
    } else {
        do {  //  Check that user input is a char
            cout << "Please enter command code: ";
            cin >> command;
        } while (!isalpha(command));
        command = tolower(command); //  Convert to lowercase for easier case matching

        return command;
    }
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
        cout << endl << endl << "No computation needed." << endl;
        return false;
    }
    else {
        return true;
    }
}