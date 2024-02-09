#ifndef INTARRAY_H
#define INTARRAY_H

#include <exception>
#include <string>

class IntArray {
private:
    int* array;       // Pointer to the array of integers
    int capacity;     // Total capacity of the array
    int count;        // Current number of elements in the array

public:
    IntArray(int initialSize = 10); // Constructor with default initial size
    ~IntArray();                    // Destructor

    int find(int value) const;                    // Function 1
    void modify(int index, int newValue);         // Function 2
    void add(int value);                          // Function 3
    void replaceOrRemove(int index);              // Function 4

    // Exception classes for error handling
    class IndexError : public std::exception {
        std::string message;
    public:
        IndexError(const std::string& msg) : message(msg) {}
        virtual const char* what() const throw() {
            return message.c_str();
        }
    };

    class CapacityError : public std::exception {
        std::string message;
    public:
        CapacityError(const std::string& msg) : message(msg) {}
        virtual const char* what() const throw() {
            return message.c_str();
        }
    };

    // Additional member functions
    void readFromFile(const std::string& filename); // Reads integers from a file
    void display() const;                           // Displays the array elements
};

#endif
