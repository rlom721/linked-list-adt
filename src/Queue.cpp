
#include "List.h"        // header file for List class
#include "Queue.h"        // header file for List class
// #include "DataClass.h"
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

    Queue::~Queue() {
        cout << "Queue destructor!" << endl;
    }

    // This method adds an entry to the back of the Queue.
    void Queue::enqueue(queueDataType& entry) {
        insertToTail(entry);
    }

    // This method removes an entry from the front of the Queue and returns it.
    Queue::queueDataType Queue::dequeue() {
        queueDataType topData = getFirstData(); // temporarily store to return after deletion

        removeHead();

        return topData;
    }

    // This method sorts the items in the queue in ascending order.
    void Queue::sort() {
        sortAsc();
    }

    // This method sorts the items in the queue in descending order.
    void Queue::sortDsc() {
        sortDesc();
    }
}