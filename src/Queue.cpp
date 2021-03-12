// Implementation file for Queue class
// File name: Queue.cpp

#include "List.h"        // header file for List class
#include "Queue.h"       // header file for Queue class
#include <iostream>
using namespace std;
namespace lomboy_a2 {

    // Default constructor sets default values of members
    Queue::Queue() : size(0) { }

    // Parametrized constructor sets default values of members, then inserts a new
    // entry into list.
    Queue::Queue(queueDataType& entry) : size(0) { 
        enqueue(entry);
    }

    // Copy constructor calls base class copy constructor
    Queue::Queue(const Queue& s) : List(s) {}

    // This method adds an entry to the back of the Queue.
    void Queue::enqueue(queueDataType& entry) {
        insertToTail(entry);
        size = getSize();
    }

    // This method removes an entry from the front of the Queue and returns it.
    Queue::queueDataType Queue::dequeue() {
        iterator frontItem = start();        // assign iterator to front item
        queueDataType frontData = *frontItem; // store data of item to return after deletion

        // remove item and update size
        removeHead();
        size = getSize(); 

        return frontData;
    }

    // This method sorts the items in the queue in ascending order.
    void Queue::sort() {
        sortAsc();
    }

    // This method sorts the items in the queue in descending order.
    void Queue::sortDsc() {
        sortDesc();
    }

    // This method searches for item with matching key in queue.
    bool Queue::searchQ(int key) {
        return search(key);
    }

    // This method returns true if queue is empty.
    bool Queue::isEmpty() const { 
        return (size == 0); 
    }
}