#include <iostream>
#include "UnitTester.h"
#include "DataClass.h"
#include "ListItem.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;
using namespace lomboy_a2;

// function prototypes
// void GenListReport();
// void GenStackReport();
// void GenQueueReport();

int main () {

    cout << "LIST CLASS\n";

    DataClass dc(0.7), dc1(1.1), dc2(2.4), dc3(3.5);

    List tList(dc);
    // cout << tList << endl;
    cout << "tList init with data: " << dc << endl;

    tList.insertToHead(dc1);
    cout << "Inserted to head\n";
    tList.traverse();
    cout << endl;

    tList.insertToTail(dc2);
    cout << "Inserted to tail\n";
    tList.traverse();
    cout << endl;

    tList.insertToMid(dc3);
    cout << "Inserted to mid\n";
    tList.traverse();
    cout << endl;

    tList.removeHead();
    cout << "Removed head\n";
    tList.traverse();
    cout << endl;

    tList.removeHead();
    cout << "Removed head\n";
    tList.traverse();
    cout << endl;

    tList.insertToMid(dc);
    cout << "Inserted to mid\n";
    tList.traverse();
    cout << endl;

    tList.removeTail();
    cout << "Removed tail\n";
    tList.traverse();
    cout << endl;

    tList.insertToMid(dc1);
    cout << "Inserted to mid\n";
    tList.traverse();
    cout << endl;

    // tList.insertToMid(dc2);
    // cout << "Inserted to mid\n";
    // tList.traverse();
    // cout << endl;
    cout << "List size: " << tList.getSize() << endl;

    cout << "Testing search method:\n";
    cout << "Looking for key of 0... " << tList.search(0) << endl;
    cout << "Looking for key of 4... " << tList.search(4) << endl;
    cout << "Looking for key of 7... " << tList.search(7) << endl;
    cout << "Looking for key of 3... " << tList.search(3) << endl;
    cout << "Looking for key of 2... " << tList.search(2) << endl;

    cout << "Sorting in ascending order...\n";
    tList.traverse();
    tList.sortAsc();
    tList.traverse();

    cout << "\nSorting in descending order...\n";
    tList.traverse();
    tList.sortDesc();
    tList.traverse();

    // testing Stack
    DataClass s0(0.1), s1(0.2), s3(0.3), s4;
    Stack sTest(s0);

    cout << "\nShowing Stack!\n";
    sTest.traverse();

    sTest.push(s1);
    sTest.traverse();
    cout << "Data at top: " << sTest.showTop() << endl;

    s4 = sTest.pop();

    cout << "Popped data " << s4 << " off stack!\n";
    sTest.traverse();

    // testing Queue
    Queue qTest(s0);

    cout << "\nShowing Queue!\n";
    qTest.traverse();

    qTest.enqueue(s1);
    qTest.traverse();

    s4 = qTest.dequeue();

    cout << "Popped data " << s4 << " off queue!\n";
    qTest.traverse();

    cout << "Adding items...\n";
    qTest.enqueue(s3);
    qTest.enqueue(s4);
    qTest.traverse();

    cout << "Sorting in ascending order...\n";
    qTest.sort();
    qTest.traverse();

    cout << "Sorting in descending order...\n";
    qTest.sortDesc();
    qTest.traverse();

    return 0;
}
