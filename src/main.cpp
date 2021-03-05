// Program Name:    List, Stack and Queue Stub
// File Name:       main.cpp
// Author:          Rafaela Lomboy
// Date:            2021.03.05
// Description:     This program demonstrates features of the List class, and its
//                  derivatives Stack and Queue classes. It generates stub reports
//                  showing various constructors and methods.

#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;
using namespace lomboy_a2;

int main () {
    List tList;     // objects for generating class reports
    Stack tStack;  
    Queue tQueue;

    // generate reports on classes as text files
    tList.GenStubReport();          // generates two reports (unordered and ordered)
    tStack.GenStackStubReport();    // generates Stack-Stub-Report.txt
    tQueue.GenQueueStubReport();    // generates Queue-Stub-Report.txt

    return 0;
}
