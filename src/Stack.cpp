
#include "List.h"        // header file for List class
#include "Stack.h"        // header file for List class
// #include "DataClass.h"
#include <iostream>
using namespace std;
namespace lomboy_a2 {

    // Default constructor sets default values of members
    Stack::Stack() : size(0) { }

    // Parametrized constructor sets default values of members, then inserts a new
    // entry into list.
    Stack::Stack(stackDataType& entry) : size(0) { 
        push(entry);
    }

    Stack::~Stack() {
        cout << "Stack destructor!" << endl;
    }

    // This method adds an entry to the stack.
    void Stack::push(stackDataType& entry) {
        insertToHead(entry);
    }

    // This method pops an entry off the top of the stack and returns it.
    Stack::stackDataType Stack::pop() {
        stackDataType topData = getFirstData(); // temporarily store to return after deletion

        removeHead();

        return topData;
    }

    // This method shows the top entry of the stack.
    Stack::stackDataType Stack::showTop() {
        return getFirstData();
    }
}