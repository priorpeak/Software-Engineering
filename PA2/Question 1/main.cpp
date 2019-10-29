#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
#include <cstdlib>

#include "pa2Functions.h"

using namespace std;

int num1, num2, counter, lineCount = 0;
const int ENTRIES = 10;
double first, last, delta = 0;
char command;
string filename, fileInput, line;
const char *charArray[256];
const char *charArray2[256];
bool file, fileIn; // file is a boolean that gets tripped when writing to a file, fileIn is a boolean that gets tripped when reading from a file

ofstream writeFile;
ifstream input;

int main() {
    // Print header
    initialize();

    do {
        // Error check user input
        if (!checkCode(selectCommand())) {
            cout << "Invalid command code" << endl;
        }
        
        // Match user input with relevant function in pa2Functions.h
        switch (command) {
            case 'f': 
                if (fileIn) {
                    getline(input, line);
                    num1 = atof(line.c_str());
                } else {
                    cout << "Please enter a number to return the factorial: ";
                    cin >> num1;
                }
                num2 = factorial(num1);
                cout << "The factorial of "<< num1 << " is " << num2 << endl;
                cout << endl << endl;

                if (file) {
                    writeFile << "The factorial of "<< num1 << " is " << num2 << endl;
                    writeFile << endl << endl;  
                }
                break;
            case 'b':
                if (fileIn) {
                    getline(input, line);
                    num1 = atof(line.c_str());
                } else {
                    cout << "Please enter a number: ";
                    cin >> num1;
                }
                num2 = fibonacci(num1);
                cout << "The Fibonacci number at index " << num1 << " is " << num2 << endl;
                cout << endl << endl;

                if (file) {
                    writeFile << "The Fibonacci number at index " << num1 << " is " << num2 << endl;
                    writeFile << endl << endl;
                }
                break;
            case 'r':
                if (checkInput()) {
                    cout << endl << endl;
                    if (first + delta > last) {
                        cout << findSqrtValue(first) << endl;
                        cout << findSqrtValue(last) << endl;

                        if (file) {
                            writeFile << findSqrtValue(first) << endl;
                            writeFile << findSqrtValue(last) << endl; 
                        }
                } else {
                    for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                        cout << findSqrtValue(i) << endl;
                        if (file) {
                            writeFile << findSqrtValue(i) << endl;
                        }
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

                        if (file) {
                            writeFile << areaSquare(first) << endl;
                            writeFile << areaSquare(last) << endl;
                        }
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << areaSquare(i) << endl;
                            if (file)
                                writeFile << areaSquare(i) << endl;
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

                        if (file) {
                            writeFile << areaCircle(first) << endl;
                            writeFile << areaCircle(last) << endl;
                        }
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << areaCircle(i) << endl;
                            if (file)
                                writeFile << areaCircle(i) << endl;
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

                            if (file)
                                writeFile << findNextEvenValue(i) << endl;
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

                        if (file) {
                            writeFile << lucky(first) << endl;
                            writeFile << lucky(last) << endl;
                        }
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << lucky(i) << endl;
                            if (file)
                                writeFile << lucky(i) << endl;
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

                        if (file) {
                            writeFile << doMath(first, 's') << endl;
                            writeFile << doMath(last, 's') << endl;
                        }
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << doMath(i, 's') << endl;
                            if (file)
                                writeFile << doMath(i, 's') << endl;
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

                        if (file) {
                            writeFile << doMath(first, 'n') << endl;
                            writeFile << doMath(last, 'n') << endl;
                        }
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << doMath(i, 'n') << endl;
                            if (file)
                                writeFile << doMath(i, 'n') << endl;
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

                        if (file) {
                            writeFile << doMath(first, 'x') << endl;
                            writeFile << doMath(last, 'x') << endl;
                        }
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << doMath(i, 'x') << endl;
                            if (file)
                                writeFile << doMath(i, 'x') << endl;
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

                        if (file) {
                            writeFile << naturalLog(first) << endl;
                            writeFile << naturalLog(last) << endl;
                        }
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << naturalLog(i) << endl;
                            if (file)
                                writeFile << naturalLog(i) << endl;
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

                        if (file) {
                            writeFile << findNyanCatValue(first) << endl;
                            writeFile << findNyanCatValue(last) << endl;
                        }
                    } else {
                        for (int i = first; i <= last && counter <= ENTRIES; i += delta) {
                            cout << findNyanCatValue(i) << endl;
                            if (file)
                                writeFile << findNyanCatValue(i) << endl;
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
                            if (file)
                                writeFile << findNextOddValue(i) << endl;
                            counter++;
                        }
                    }
                counter = 0;
                }
                cout << endl << endl;
                break;
            case 'i': {
                cout << endl << endl;
                cout << "Please enter a filename to read from: ";
                cin >> fileInput;
                const char *charArray2 = fileInput.c_str();
                readDataFromFile(charArray2);

                // Count number of lines in input file
                while(getline(input, line))
                    lineCount++;

                // Set bool fileIn to true in order to read content from file and match to relevant operations
                fileIn = true;
            }
                break;
            case 'o': {
                cout << endl << endl;
                cout << "Please enter a filename to write to: ";
                cin >> filename;
                const char *charArray = filename.c_str();
                writeDataToFile(charArray);

                // Set bool file to true in order to write content from this point forward
                file = true;
            }   
                break;
            default:
                break;
        }
    } while (command != 'q');  

    // If a file has been opened for writing, close it before exiting the program
    if (writeFile.is_open())
        writeFile.close();

    cout << "Program exiting" << endl;

    return 0;
}