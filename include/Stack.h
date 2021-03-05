// Specification file for Stack class
//
// Inherited class from List class
// [DESC]

#ifndef STACK_H
#define STACK_H

#include "List.h"    // header file for ListItem class
namespace lomboy_a2 {

    class Stack : public List {
    public:
        // typedef
        typedef List::listType stackDataType;
        // Constructors
        Stack();
        Stack(stackDataType& entry);
        Stack(const Stack&);    // copy
        // Modification methods
        void push(stackDataType& entry);
        stackDataType pop();
        // Constant methods
        void showStack();
        bool isEmpty() const;
        stackDataType showTop();
        void GenStackStubResults();      // shows functionality of List class
        void GenStackStubReport();
    private:
        int size;
    };

}

#endif