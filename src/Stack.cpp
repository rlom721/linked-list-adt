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
        iterator topItem = start();       // assign iterator to top item
        stackDataType topData = *topItem; // store data of item to return after deletion

        // remove item and update size
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

    // This method returns true if there is no space to allocate a new item on stack.
    // It also throws an exception to indicate a bad_alloc.
    bool Stack::isFull() const { 
        return canAllocate();
    }

    // This method shows the top entry of the stack.
    Stack::stackDataType Stack::showTop() {
        iterator topItem = start();       // assign iterator to top item
        stackDataType topData = *topItem; // store data of item to return after deletion

        return topData;
    }
}