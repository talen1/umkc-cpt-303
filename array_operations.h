#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

#include <vector>
#include <stdexcept>

class ArrayOperations {
public:
    ArrayOperations(const std::string& filename);
    bool integerExists(int number);
    std::pair<int, int> modifyValue(int index, int newValue);
    void addInteger(int number);
    void replaceOrRemove(int index, int newValue);

private:
    std::vector<std::vector<int>> data;
    void loadDataFromFile(const std::string& filename);
};

#endif // ARRAY_OPERATIONS_H
