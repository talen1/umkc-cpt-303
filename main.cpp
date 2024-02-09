#include "IntArray.h"
#include <iostream>

int main() {
    IntArray myArray(100); // Assuming the file does not have more than 100 integers

    try {
        myArray.readFromFile("A1input.txt"); // Make sure to place A1input.txt in the correct directory
    } catch (const std::exception& e) {
        std::cerr << "Error reading from file: " << e.what() << std::endl;
        return 1;
    }

    myArray.display(); // Display the array after reading from file

    try {
        // Modify value at index 5 to 500
        myArray.modify(5, 500);
        std::cout << "Modified index 5 to 500." << std::endl;
    } catch (const IntArray::IndexError& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // Add value 200 to the end of the array
        myArray.add(200);
        std::cout << "Added 200 to the end of the array." << std::endl;
    } catch (const IntArray::CapacityError& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    myArray.display(); // Display the array after modifications

    // Replace or remove an element at index 2
    try {
        myArray.replaceOrRemove(2);
        std::cout << "Removed element at index 2." << std::endl;
    } catch (const IntArray::IndexError& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    myArray.display(); // Final display of the array

    return 0;
}
