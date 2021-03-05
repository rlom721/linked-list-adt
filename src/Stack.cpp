
#include "List.h"        // header file for List class
#include "Stack.h"        // header file for List class
#include <iostream>
#include <fstream>      // for writing files
using namespace std;
namespace lomboy_a2 {

    // Default constructor sets default value of size
    Stack::Stack() : size(0) {}

    // Parametrized constructor sets default values of members, then inserts a new
    // entry into list.
    Stack::Stack(stackDataType& entry) : size(0) { 
        push(entry);
    }

    // Copy constructor calls base class copy constructor
    Stack::Stack(const Stack& s) : List(s) {}

    // This method adds an entry to the stack.
    void Stack::push(stackDataType& entry) {
        insertToHead(entry);
        size = getSize();
    }

    // This method pops an entry off the top of the stack and returns it.
    Stack::stackDataType Stack::pop() {
        stackDataType topData = start(); // temporarily store to return after deletion

        removeHead();
        size = getSize();

        return topData;
    }

    // This method displays contents of the stack.
    void Stack::showStack() {
        iterate();
    }

    // This method returns true if stack is empty.
    bool Stack::isEmpty() const { 
        return (size == 0); 
    }

    // This method shows the top entry of the stack.
    Stack::stackDataType Stack::showTop() {
        return start();
    }

        // This method generates stub program results of List methods to console to 
    // demonstrate class features.
    void Stack::GenStackStubResults() {

        cout << "STACK CLASS TEST REPORT\n\n"
             << "This displays the functionality of the Stack class, including constructor\n"
             << "use and methods using test data.\n\n";

        Stack::stackDataType s0(0.1), s1(0.2), s3(0.3), s4;
        Stack sTest(s0);

        cout << "Constructor Tests\n\n";
        cout << "Testing Parametrized Constructor...\n";
        cout << "Stack initialized with data: " << s0 << " inserted.\n";
        cout << "Showing Stack Contents:\n";
        sTest.showStack();

        cout << "\nMethods Tests\n";
        cout << "Testing push() method...\n";
        sTest.push(s1);
        sTest.showStack();

        cout << "Testing showTop() method...\n";
        cout << "Data at top: " << sTest.showTop() << endl;

        cout << "Testing pop() method...\n";
        s4 = sTest.pop();
        sTest.showStack();

        cout << "Popped data " << s4 << " off stack!\n";
    }

    // This method generates a text file with name "Stub-Report" displaying stub program results to
    // demonstrate class features.
    void Stack::GenStackStubReport() {
        ofstream outFile;

        outFile.open("Stack-Stub-Report.txt");

        outFile << "STACK CLASS TEST REPORT\n\n"
             << "This displays the functionality of the Stack class, including constructor\n"
             << "use and methods using test data.\n\n";

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
}