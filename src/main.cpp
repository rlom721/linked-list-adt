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
    List tList;     // test List class

    // tList.GenStubResults();
    tList.GenStubReport();

    // // testing Stack
    // DataClass s0(0.1), s1(0.2), s3(0.3), s4;
    // Stack sTest(s0);

    // cout << "\nShowing Stack!\n";
    // sTest.iterate();

    // sTest.push(s1);
    // sTest.iterate();
    // cout << "Data at top: " << sTest.showTop() << endl;

    // s4 = sTest.pop();

    // cout << "Popped data " << s4 << " off stack!\n";
    // sTest.iterate();

    // // testing Queue
    // Queue qTest(s0);

    // cout << "\nShowing Queue!\n";
    // qTest.iterate();

    // qTest.enqueue(s1);
    // qTest.iterate();

    // s4 = qTest.dequeue();

    // cout << "Popped data " << s4 << " off queue!\n";
    // qTest.iterate();

    // cout << "Adding items...\n";
    // qTest.enqueue(s3);
    // qTest.enqueue(s4);
    // qTest.iterate();

    // cout << "Sorting in ascending order...\n";
    // qTest.sort();
    // qTest.iterate();

    // cout << "Sorting in descending order...\n";
    // qTest.sortDesc();
    // qTest.iterate();

    // // add bounds checking
    // cout << "Testing search method:\n";
    // cout << "Looking for key of 0... " << qTest.searchQ(0) << endl;
    // cout << "Looking for key of 4... " << qTest.searchQ(4) << endl;
    // cout << "Looking for key of 7... " << qTest.searchQ(7) << endl;
    // cout << "Looking for key of 3... " << qTest.searchQ(3) << endl;
    // cout << "Looking for key of 2... " << qTest.searchQ(2) << endl;

    return 0;
}
