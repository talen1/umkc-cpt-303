#include "array_operations.h" // Include the header file for the class
#include <fstream>
#include <iostream>

// Constructor for the ArrayOperations class that takes a filename and loads data from it.
ArrayOperations::ArrayOperations(const std::string& filename) {
    loadDataFromFile(filename);
}

// Method to load data from a file into the 2D array.
void ArrayOperations::loadDataFromFile(const std::string& filename) {
    std::ifstream file(filename); // Open the file for reading
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open the file."); // Throw an exception if the file cannot be opened
    }

    data.clear(); // Clear the existing data in the array

    for (int i = 0; i < 10; ++i) {
        std::vector<int> line;
        for (int j = 0; j < 10; ++j) {
            int number;
            if (!(file >> number)) {
                throw std::runtime_error("Error reading data from the file."); // Throw an exception if there's an error reading data
            }
            line.push_back(number);
        }
        data.push_back(line); // Add the read line of integers to the 2D array
    }

    file.close(); // Close the file
}

// Method to check if a given integer exists in the 2D array.
bool ArrayOperations::integerExists(int number) {
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[i].size(); ++j) {
            if (data[i][j] == number) {
                return true; // Return true if the integer is found
            }
        }
    }
    return false; // Return false if the integer is not found
}

// Method to modify a value at a specified index in the 2D array.
std::pair<int, int> ArrayOperations::modifyValue(int index, int newValue) {
    if (index < 0 || index >= data.size() || newValue < 0) {
        throw std::invalid_argument("Invalid index or new value."); // Throw an exception for invalid index or new value
    }

    int oldValue = data[index / 10][index % 10]; // Get the old value at the specified index
    data[index / 10][index % 10] = newValue; // Modify the value with the new value
    return std::make_pair(oldValue, newValue); // Return a pair of old and new values
}

// Method to add an integer to the end of the last row in the 2D array.
void ArrayOperations::addInteger(int number) {
    if (data.size() != 10 || data[0].size() != 10) {
        throw std::runtime_error("Invalid array size."); // Throw an exception for an invalid array size
    }

    data[9].push_back(number); // Add the integer to the last row
}

// Method to replace a value at a specified index with a new value or remove it if the new value is 0.
void ArrayOperations::replaceOrRemove(int index, int newValue) {
    if (index < 0 || index >= data.size()) {
        throw std::invalid_argument("Invalid index."); // Throw an exception for an invalid index
    }

    if (newValue == 0) {
        data[index / 10].erase(data[index / 10].begin() + index % 10); // Remove the value if the new value is 0
    } else {
        data[index / 10][index % 10] = newValue; // Replace the value with the new value
    }
}
