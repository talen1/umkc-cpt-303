#include "IntArray.h"
#include <iostream>
#include <fstream>

IntArray::IntArray(int initialSize) : capacity(initialSize), count(0) {
    array = new int[capacity];
}

IntArray::~IntArray() {
    delete[] array;
}

int IntArray::find(int value) const {
    for (int i = 0; i < count; ++i) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1; // Return -1 if the value is not found
}

void IntArray::modify(int index, int newValue) {
    if (index < 0 || index >= count) {
        throw IndexError("Index out of bounds.");
    }
    array[index] = newValue;
}

void IntArray::add(int value) {
    if (count == capacity) {
        throw CapacityError("Array has reached its capacity.");
    }
    array[count++] = value;
}

void IntArray::replaceOrRemove(int index) {
    if (index < 0 || index >= count) {
        throw IndexError("Index out of bounds.");
    }
    // Shift elements left to remove the element at the index
    for (int i = index; i < count - 1; ++i) {
        array[i] = array[i + 1];
    }
    --count;
}

void IntArray::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file.");
    }
    int value;
    while (file >> value) {
        add(value);
    }
    file.close();
}

void IntArray::display() const {
    for (int i = 0; i < count; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

