#include <iostream>
#include "UnitTester.h"
#include "DataClass.h"
#include "ListItem.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;
using namespace lomboy_a2;

// Function prototypes

int main () {
    List tList;     // objects for generating class reports
    Stack tStack;  
    Queue tQueue;

    // tList.GenStubResults();
    tList.GenStubReport();

    // tStack.GenStackStubResults();
    tStack.GenStackStubReport();

    // tQueue.GenQueueStubResults();
    tQueue.GenQueueStubReport();

    return 0;
}
