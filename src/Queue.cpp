
#include "List.h"        // header file for List class
#include "Queue.h"        // header file for List class
#include <iostream>
#include <fstream>          // for writing results to file
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
        queueDataType topData = start(); // temporarily store to return after deletion

        removeHead();
        size = getSize();

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

    // This method searches for item with matching key in queue.
    bool Queue::searchQ(int key) {
        return search(key);
    }

    // This method returns true if queue is empty.
    bool Queue::isEmpty() const { 
        return (size == 0); 
    }

    // This method generates stub program results of List methods to console to 
    // demonstrate class features.
    void Queue::GenQueueStubResults() {
        cout << "QUEUE CLASS TEST REPORT\n\n"
             << "This displays the functionality of the Queue class, including constructor\n"
             << "use and methods using test data.\n\n";

        Queue::queueDataType q0(0.1), q1(0.2), q3(0.3), q4;

        // testing Queue
        Queue qTest(q0);

        cout << "\nShowing Queue!\n";
        qTest.iterate();

        qTest.enqueue(q1);
        qTest.iterate();

        q4 = qTest.dequeue();

        cout << "Popped data " << q4 << " off queue!\n";
        qTest.iterate();

        cout << "Adding items...\n";
        qTest.enqueue(q3);
        qTest.enqueue(q4);
        qTest.iterate();

        cout << "Sorting in ascending order...\n";
        qTest.sort();
        qTest.iterate();

        cout << "Sorting in descending order...\n";
        qTest.sortDesc();
        qTest.iterate();

        // add bounds checking
        cout << "Testing search method:\n";
                // look for keys from 0 to 3
        for (int i = 0; i < 4; i++) {
            cout << "Searching for key of " << i << ": "
                 << (qTest.searchQ(i) ? "found" : "not found") << endl;
        }
    }   

    // This method generates a text file with name "Stub-Report" displaying stub program results to
    // demonstrate class features.
    void Queue::GenQueueStubReport() {
        ofstream outFile;

        outFile.open("Queue-Stub-Report.txt");

        outFile << "QUEUE CLASS TEST REPORT\n\n"
             << "This displays the functionality of the Queue class, including constructor\n"
             << "use and methods using test data.\n\n";

        Queue::queueDataType q0(0.1), q1(0.2), q3(0.3), q4;

        // testing Queue
        Queue qTest(q0), qEmpty;

        outFile << "Constructor Tests\n\n";
        outFile << "Testing Default constructor...\n";
        outFile << "Queue should have no data.\n";
        outFile << qEmpty << endl;

        outFile << "Testing Parametrized Constructor...\n";
        outFile << "Queue initialized with data: " << q0 << " inserted.\n";
        outFile << "Showing Queue Contents:\n";
        outFile << qTest << endl;

        Queue qTest1(qTest);
        outFile << "Testing Copy constructor...\n";
        outFile << "Showing contents of original Queue:\n";
        outFile << qTest; 
        outFile << "Queue created with copy constructor:\n";
        outFile << qTest1 << endl;

        outFile << "Methods Tests\n\n";
        outFile << "Testing enqueue() method...\n";
        qTest.enqueue(q1);
        outFile << qTest << endl;

        outFile << "Testing dequeue() method...\n";
        q4 = qTest.dequeue();

        outFile << "Dequeued data " << q4 << " off queue!\n";
        outFile << qTest << endl;

        outFile << "Adding items...\n";
        qTest.enqueue(q3);
        qTest.enqueue(q4);
        outFile << qTest << endl;

        outFile << "Testing sort() method...\n";
        outFile << "Sorting in ascending order...\n";
        qTest.sort();
        outFile << qTest << endl;

        outFile << "Testing sortDsc() method...\n";
        outFile << "Sorting in descending order...\n";
        qTest.sortDesc();
        outFile << qTest << endl;

        // add bounds checking
        outFile << "Testing search method...\n";

        // look for keys from 0 to 3
        for (int i = 0; i < 4; i++) {
            outFile << "Searching for key of " << i << ": "
                 << (qTest.searchQ(i) ? "found" : "not found") << endl;
        }

        outFile << "\nTesting isEmpty() method...\n";
        outFile << "Queue is " << (qTest.isEmpty() ? "empty" : "not empty") << endl;

        outFile.close();
    }

}