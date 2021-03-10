// Implementation file for Stack class
// File name: Stack.cpp

#include "List.h"        // header file for List class
#include "Stack.h"       // header file for Stack class
#include <iostream>
using namespace std;
namespace lomboy_a2 {

    // Default constructor sets default value of size
    Stack::Stack() : size(0) {}

    // Parametrized constructor sets default values of members, then inserts a new
    // entry into list.
    Stack::Stack(stackDataType& entry) : size(0) { 
        push(entry);
    }

    // Copy constructor calls base class copy constructor
    Stack::Stack(const Stack& s) : List(s) {}

    // This method adds an entry to the stack.
    void Stack::push(stackDataType& entry) {
        insertToHead(entry);
        size = getSize();
    }

    // This method pops an entry off the top of the stack and returns it.
    Stack::stackDataType Stack::pop() {
        stackDataType topData = start(); // temporarily store to return after deletion

        removeHead();
        size = getSize();

        return topData;
    }

    // This method displays contents of the stack.
    void Stack::showStack() {
        iterate();
    }

    // This method returns true if stack is empty.
    bool Stack::isEmpty() const { 
        return (size == 0); 
    }

    // This method shows the top entry of the stack.
    Stack::stackDataType Stack::showTop() {
        return start();
    }
}