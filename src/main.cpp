// Program Name:    List, Stack and Queue Stub
// File Name:       main.cpp
// Author:          Rafaela Lomboy
// Date:            2021.03.05
// Description:     This program demonstrates features of the List class, and its
//                  derivatives Stack and Queue classes. It generates stub reports
//                  showing various constructors and methods.

#include <iostream>
#include <fstream>          // for reading and writing to data files
#include "List.h"           // testing base class
#include "Stack.h"          // testing derived class (parent is List class)
#include "Queue.h"          // testing derived class (parent is List class)
#include "DataClass.h"      // for producing test data
using namespace std;
using namespace lomboy_a2;

// TODO :
// add iterator class
// summon iterator class to access List container contents
// add isFull method to List class

// function prototypes
void GenListStubReports();          
void GenStackStubReport();
void GenQueueStubReport();

int main () {

    // generate reports on classes as text files
    GenListStubReports();    // generates two reports (unordered and ordered)
    GenStackStubReport();    // generates Stack-Stub-Report.txt
    GenQueueStubReport();    // generates Queue-Stub-Report.txt

    return 0;
}

// This function generates two text files with names "List-Unordered-Report" and
// "List-Ordered-Report" displaying stub program results to demonstrate List class 
// features (constructors and methods).
void GenListStubReports() {
    ofstream outFile1, outFile2;

    // open files
    outFile1.open("List-Unordered-Report.txt");
    outFile2.open("List-Ordered-Report.txt");

    // print out data for Unordered Operations
    outFile1 << "LIST CLASS UNORDERED OPERATIONS REPORT\n\n"
            << "This displays the functionality of the List class, including constructor\n"
            << "use and methods using test data. Only unordered operations shown.\n\n";
    
    // test data
    DataClass dc(0.7), dc1(1.1), dc2(2.4), dc3(3.5);

    List tList(dc), tList1;         // for testing

    outFile1 << "Constructor Tests\n\n";
    outFile1 << "Testing Default constructor...\n";
    outFile1 << "List 2 should have no data.\n";
    outFile1 << tList1 << endl;

    outFile1 << "Testing Parametrized constructor...\n";
    outFile1 << "List 1 initialized with data " << dc << " inserted at start.\n";
    outFile1 << tList;

    outFile1 << "\nMethod Tests\n";
    outFile1 << "Testing insertToHead() method...";
    tList.insertToHead(dc1);
    outFile1 << "\nInserting " << dc1 << " to head...\n";
    outFile1 << tList;

    tList.insertToTail(dc2);
    outFile1 << "\nTesting insertToTail() method...";
    outFile1 << "\nInserting " << dc2 << " to tail...\n";
    outFile1 << tList;

    tList.insertToMid(dc3);
    outFile1 << "\nTesting insertToMid() method...";
    outFile1 << "\nInserting " << dc3 << " to middle...\n";
    outFile1 << tList;

    tList.removeHead();
    outFile1 << "\nTesting removeHead() method...\n";
    outFile1 << "Removed item at head.\n";
    outFile1 << tList;

    tList.removeTail();
    outFile1 << "\nTesting removeTail() method...\n";
    outFile1 << "Removed item at tail\n";
    outFile1 << tList;

    tList.insertToMid(dc);
    outFile1 << "\nInserting " << dc << " to middle...\n";
    outFile1 << tList << endl;

    tList.insertToMid(dc1);
    outFile1 << "\nInserting " << dc1 << " to middle...\n";
    outFile1 << tList;

    tList.remove(4);
    outFile1 << "\nTesting remove() method...\n";
    outFile1 << "Removed item with key 4.\n";
    outFile1 << tList << endl;

    outFile1 << "Testing getSize() method...\n";
    outFile1 << "List size: " << tList.getSize() << endl;

    outFile1 << "\nTesting search() method...\n";

    // look for keys from 0 to 3
    for (int i = 0; i < 4; i++) {
        outFile1 << "Searching for key of " << i << ": "
                << (tList.search(i) ? "found" : "not found") << endl;
    }

    outFile1 << "\nTesting getData() method...\n";
    outFile1 << "Getting item with key 5: " << tList.getData(5) << endl;

    // print out data for Unordered Operations
    outFile2 << "LIST CLASS ORDERED OPERATIONS REPORT\n\n"
            << "This displays the functionality of the List class, including copy constructor\n"
            << "use and methods using test data. Only ordered operations shown.\n\n";

    List tList2(tList);     // copy contents of first list used above

    outFile2 << "Copy Constructor Test\n\n";
    outFile2 << "Testing Copy constructor...\n";

    outFile2 << "Showing contents of original list:\n";
    outFile2 << tList << endl; 
    outFile2 << "List created with copy constructor:\n";
    outFile2 << tList2;

    outFile2 << "\nTesting sortAsc() method...";
    outFile2 << "\nSorting in ascending order.\n";
    tList2.sortAsc();
    outFile2 << tList2;

    outFile2 << "\nTesting sortDesc() method...";
    outFile2 << "\nSorting in descending order.\n";
    tList2.sortDesc();
    outFile2 << tList2 << endl;

    // outFile2 << "Testing start() method...\n";
    // outFile2 << "Showing item data at start: " << tList2.start() << endl;

    // outFile2 << "\nTesting getNext() method...\n";
    // outFile2 << "Showing next item data: " << tList2.getNext() << endl;

    // outFile2 << "\nTesting hasNext() method...\n";
    // outFile2 << "Is there item after current? " 
    //             << (tList2.hasNext() ? "Yes" : "No") << endl;

    // outFile2 << "\nTesting end() method...\n";
    // outFile2 << "Showing item data at end: " << tList2.end() << endl;

    outFile2 << "Testing List Iterator methods...\n";

    // List::iterator iter = tList2.start();

    // while (iter.hasNext()) {
    //     cout << *iter << endl;
    //     ++iter;
    // }

    for (List::iterator iter = tList2.start(); iter.hasNext(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    // tList2.iterate();

    // close files
    outFile1.close();
    outFile2.close();
}

// This function generates a text file with name "Stack-Stub-Report" displaying 
// stub program results to demonstrate Stack class features (constructors and methods).
void GenStackStubReport() {
    ofstream outFile;

    outFile.open("Stack-Stub-Report.txt");

    outFile << "STACK CLASS TEST REPORT\n\n"
            << "This displays the functionality of the Stack class, including constructor\n"
            << "use and methods using test data.\n\n";

    // test data
    DataClass s0(0.1), s1(0.2), s3(0.3), s4;
    Stack sTest(s0), sEmpty;

    outFile << "Constructor Tests\n\n";
    outFile << "Testing Default constructor...\n";
    outFile << "Stack should have no data.\n";
    outFile << sEmpty << endl;

    outFile << "Testing Parametrized Constructor...\n";
    outFile << "Stack initialized with data: " << s0 << " inserted.\n";
    outFile << "Showing Stack Contents:\n";
    outFile << sTest << endl;

    Stack sTest2(sTest);
    outFile << "Testing Copy constructor...\n";
    outFile << "Showing contents of original stack:\n";
    outFile << sTest; 
    outFile << "Stack created with copy constructor:\n";
    outFile << sTest2 << endl;

    outFile << "Methods Tests\n\n";
    outFile << "Testing push() method...\n";
    sTest.push(s1);
    outFile << sTest << endl;

    outFile << "Testing showTop() method...\n";
    outFile << "Data at top: " << sTest.showTop() << endl;

    outFile << "Testing pop() method...\n";
    s4 = sTest.pop();
    outFile << sTest << endl;

    outFile << "Popped data " << s4 << " off stack!\n";

    outFile << "\nTesting isEmpty() method...\n";
    outFile << "Stack is " << (sTest.isEmpty() ? "empty" : "not empty") << endl;

    outFile.close();
}

// This function generates a text file with name "Queue-Stub-Report" displaying 
// stub program results to demonstrate Queue class features (constructors and methods).
void GenQueueStubReport() {
    ofstream outFile;

    outFile.open("Queue-Stub-Report.txt");

    outFile << "QUEUE CLASS TEST REPORT\n\n"
            << "This displays the functionality of the Queue class, including constructor\n"
            << "use and methods using test data.\n\n";

    // test data
    DataClass q0(0.1), q1(0.2), q3(0.3), q4;

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