#include <iostream>

using namespace std;

int * ReverseMultiply(int *list, int size);
int * ReverseAdd(int *list, int size);

int main() {
    int size = 0;
    
    // User input for array size
    cout << "Enter an array size: ";
    cin >> size;

    // Initialize a new array to the given size
    int list[size];

    // Loop through the empty array to input values
    for (int i = 0; i < size; i++) {
        cout << "Enter a value for index " << i << ": ";
        cin >> list[i];
    }

    // Call to functions
    int *new_array = ReverseMultiply(list, size);
    int *array2 = ReverseAdd(list, size);

    // Print statements
    cout << "Original array is: ";
    for (int i = 0; i < size; i++)
        cout << list[i] << " ";
    
    cout << "and the address of the zero element is: " << list << endl;

    cout << "One array is: ";
    for (int i = 0; i < (size * 2 + 1); i++)
        cout << new_array[i] << " ";

    cout << "and the address of the zero element is: " << new_array << endl;

    cout << "Two array is: ";
    for (int i = 0; i < (size * 2 - 1); i++)
        cout << array2[i] << " ";

    cout << "and the address of the zero element is: " << array2 << endl;

    return 0;
}

int * ReverseMultiply(int *list, int size) {
    // Initialize new array
    int *new_array = new int[2 * size + 1];

    // Copy old array into first half of new array
    for (int i = 0; i < size; i++)
        new_array[i] = list[i];

    // Reverse old array and copy into second half of new array
    int j = size - 1;
    for (int i = size; i < (2 * size); i++) {
        new_array[i] = list[j];
        j--;
    }

    // Add running product to the end of new array
    int running_prod = new_array[0];
    for (int i = 1; i < (2 * size); i++)
        running_prod *= new_array[i];

    new_array[2 * size] = running_prod;

    return new_array;
}

int * ReverseAdd(int *list, int size) {
    // Initialize array2
    int *array2 = new int[2 * size - 1];

    // Copy old array into first half of array2
    for (int i = 0; i < size; i++)
        array2[i] = list[i];

    // Add a running sum to the second half of the array
    int running_sum = array2[0];
    int j = size - 1;
    for (int i = size; i < (2 * size -1); i++) {
        array2[i] = array2[j] + array2[j - 1];
        j--;
    }

    return array2;
}