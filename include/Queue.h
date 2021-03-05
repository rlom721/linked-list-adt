// Specification file for Stack class
//
// Inherited class from List class
// [DESC]

#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"    // header file for ListItem class
namespace lomboy_a2 {

    class Queue : public List {
    public:
        // typedef
        typedef List::listType queueDataType;
        // Constructors
        Queue();
        Queue(queueDataType& entry);
        Queue(const Queue&);    // copy
        // Modification methods
        void enqueue(queueDataType& entry);
        queueDataType dequeue();
        void sort();            // default sorts ascending
        void sortDsc();
        // Constant methods
        bool searchQ(int key);
        bool isEmpty() const;
        // Test methods
        void GenQueueStubResults();      // shows functionality of List class
        void GenQueueStubReport();
    private:
        int size;
    };

}

#endif