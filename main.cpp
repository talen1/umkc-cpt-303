#include "array_operations.h"
#include <fstream>
#include <iostream>

ArrayOperations::ArrayOperations(const std::string& filename) {
    loadDataFromFile(filename);
}

void ArrayOperations::loadDataFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open the file.");
    }

    data.clear();

    for (int i = 0; i < 10; ++i) {
        std::vector<int> line;
        for (int j = 0; j < 10; ++j) {
            int number;
            if (!(file >> number)) {
                throw std::runtime_error("Error reading data from the file.");
            }
            line.push_back(number);
        }
        data.push_back(line);
    }

    file.close();
}

bool ArrayOperations::integerExists(int number) {
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[i].size(); ++j) {
            if (data[i][j] == number) {
                return true;
            }
        }
    }
    return false;
}

std::pair<int, int> ArrayOperations::modifyValue(int index, int newValue) {
    if (index < 0 || index >= data.size() || newValue < 0) {
        throw std::invalid_argument("Invalid index or new value.");
    }

    int oldValue = data[index / 10][index % 10];
    data[index / 10][index % 10] = newValue;
    return std::make_pair(oldValue, newValue);
}

void ArrayOperations::addInteger(int number) {
    if (data.size() != 10 || data[0].size() != 10) {
        throw std::runtime_error("Invalid array size.");
    }

    data[9].push_back(number);
}

void ArrayOperations::replaceOrRemove(int index, int newValue) {
    if (index < 0 || index >= data.size()) {
        throw std::invalid_argument("Invalid index.");
    }

    if (newValue == 0) {
        data[index / 10].erase(data[index / 10].begin() + index % 10);
    } else {
        data[index / 10][index % 10] = newValue;
    }
}
