#include <iostream>
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

    // generate reports on classes as text files
    tList.GenStubReport();   // this generates two reports (unordered and ordered)
    tStack.GenStackStubReport();
    tQueue.GenQueueStubReport();

    return 0;
}
