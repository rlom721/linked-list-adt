
// #include "DataClass.h"    // header file for ListItem class
#include "List.h"        // header file for List class
#include "ListItem.h"    // header file for ListItem class
#include <iostream>
#include <fstream>      // for reading and writing to data files
using namespace std;
namespace lomboy_a2 {

    // Default constructor sets default values of members
    List::List()
        : iterator(nullptr), headPtr(nullptr), tailPtr(nullptr), size(0), isSorted(false), keyMkr(0) { 
    }

    // Parametrized constructor sets default values of members, then inserts a new
    // entry into list.
    List::List(listType data)
        : iterator(nullptr), headPtr(nullptr), tailPtr(nullptr), size(0), isSorted(false), keyMkr(0) {
        insertToTail(data);
    }

    // Copy constructor performs deep copy by copying data of elements into ListItems
    // of a NEW location (so pointers don't point to original)
    List::List(const List& l) {
        // initialize variables of THIS list
        headPtr = nullptr;
        tailPtr = nullptr;
        iterator = nullptr;
        size = 0;
        isSorted = false;
        keyMkr = 0;

        ListItem* listPtr = l.headPtr;    // to iterate through list
        listType entryCopy;               // to add data to new list
        
        // for empty list
        if (l.headPtr == nullptr)
            return;

        // iterate through to copy item data into new list
        while (listPtr != nullptr) {

            entryCopy = listPtr->getData();
            this->insertToTail(entryCopy);

            listPtr = listPtr->getNext();
        }

        // avoid dangling pointer
        listPtr = nullptr;
    }

    // Destructor frees allocated memory through list
    List::~List() {
        cout << "List Destructor!\n";
        clearList();
    }

    // This is insert method adds new ListItem to head of list.
    void List::insertToHead(const listType& entry) {
        insert(entry, headPtr);
    }

    // This is insert method adds new ListItem to tail of list.
    void List::insertToTail(const listType& entry) {
        insert(entry, tailPtr);
    }

    // FIX - not putting it in middle!
    // This is insert method adds new ListItem to middle of list.
    void List::insertToMid(const listType& entry) {
        ListItem* listPtr = headPtr;    // to go through list
        ListItem* newItemPtr = new ListItem(entry); // new item has entry data

        newItemPtr->setKey(keyMkr++);   // set unique key of item

        int item = 0;      // places to move in list

        // empty list case sets head and tail to new item
        if (headPtr == nullptr) {
            headPtr = newItemPtr;
            tailPtr = newItemPtr;
        }

        while (item < ((size - 1) / 2)) {
            listPtr = listPtr->getNext();
            item++;
        }

        // insert to middle location, after listPtr
        ListItem* nextItemPtr;      // points to item AFTER listPtr
        nextItemPtr = listPtr->getNext();

        // link new item to listPtr and to next
        newItemPtr->setPrev(listPtr);
        newItemPtr->setNext(nextItemPtr);
        
        // link listPtr to new and next to new
        listPtr->setNext(newItemPtr);
        nextItemPtr->setPrev(newItemPtr);

        size++;

        // to prevent dangling pointer!
        nextItemPtr = nullptr;
        listPtr = nullptr;
    }

    // This method deletes item with a matching key.
    void List::remove(int key) {
        ListItem* temp;     // points to item to delete
        // ListItem* prevItem, nextItem;   // to be used in remove from middle case
        temp = find(key);   // if found, returns pointer to item. if not, nullptr

        // list is empty
        if (headPtr == nullptr) {
            cout << "List is empty.\n";
        }
        // item not found
        else if (temp == nullptr) {
            cout << "Invalid key.\n";
        }
        // remove from head by setting headPtr to next
        else if (temp == headPtr) {
            headPtr = temp->getNext();

            // set headPtr to next item if after delete list has more than one item, 
            if (headPtr != nullptr)
                headPtr->setPrev(nullptr);
            else 
                tailPtr = nullptr;
        }
        // remove from tail by setting tailPtr to prev
        else if (temp == tailPtr) {
            tailPtr = temp->getPrev();

            // set tailPtr to next item if after delete list has more than one item, 
            if (headPtr != nullptr)
                tailPtr->setNext(nullptr);
            else 
                headPtr = nullptr;
        }
        // remove from middle by linking previous and next to each other
        else {
            ListItem* prevItem = temp->getPrev();   // item before temp
            ListItem* nextItem = temp->getNext();   // item after temp
            // prevItem = temp->getPrev();   // item before temp
            // nextItem = temp->getNext();   // item after temp

            // link previous to next and next to previous
            prevItem->setNext(nextItem);
            nextItem->setPrev(prevItem);

            // set temp pointers to nullptr
            prevItem = nullptr;
            nextItem = nullptr;
        }

        size--;

        // free memory of unlinked item, and null out temp pointers used
        delete temp;  
        temp = nullptr;
        // prevItem = nullptr;
        // nextItem = nullptr;
    }

    // This method deletes item at head.
    // Works for empty list and one list item cases.
    void List::removeHead() {
        int headKey = -1;

        if (headPtr != nullptr)
            headKey = headPtr->getDataKey();    // to use with remove function

        if (headKey != -1) remove(headKey);
    }

    // This method deletes item at tail.
    // Works for empty list and one list item cases.
    void List::removeTail() {
        int tailKey = -1;

        if (tailPtr != nullptr)
            tailKey = tailPtr->getDataKey();    // to use with remove function

        if (tailKey != -1) remove(tailKey);
    }

    // This method searches through the list for a matching key, returning true if 
    // found and false if not.
    bool List::search(int key) {
        ListItem* itemPtr;      // to point to found item
        itemPtr = find(key);    // if found, returns pointer to item. if not, nullptr

        if (itemPtr != nullptr)
            return true;

        return false;                               
    }

    // This method implements the selection sort algorithm to sort items in list.
    void List::sortAsc() {
        ListItem* item1ptr = headPtr;             // iterate through inner loop
        ListItem* item2ptr = headPtr->getNext();  // iterate through outer loop
        int outCount = 0,       // outer loop count (1st item)
            inCount = 0;        // inner loop count (2nd item)

        // outer loop controls iterations of first item value to compare
        // inner loop compares rest of list values to first each iteration
        while (item1ptr != nullptr && outCount < size - 1) {
            // move inner loop pointer back to right after item1ptr
            item2ptr = item1ptr->getNext();     
            while (item2ptr != nullptr && inCount < size) {
                // item2ptr's data is less, so swap data and key
                if (item2ptr->getData() < item1ptr->getData())
                    swapItems(*item1ptr, *item2ptr);

                item2ptr = item2ptr->getNext(); // point to next item
                inCount++;
            }
            item1ptr = item1ptr->getNext(); // point to next item
            outCount++;
        }
        // prevent dangling pointers!
        item1ptr = nullptr;
        item2ptr = nullptr;
    }
    // This method implements the selection sort algorithm to sort items in list.
    void List::sortDesc() {
        ListItem* item1ptr = headPtr;             // iterate through inner loop
        ListItem* item2ptr = headPtr->getNext();  // iterate through outer loop
        int outCount = 0,       // outer loop count (1st item)
            inCount = 0;        // inner loop count (2nd item)

        // outer loop controls iterations of first item value to compare
        // inner loop compares rest of list values to first each iteration
        while (item1ptr != nullptr && outCount < size - 1) {
            // move inner loop pointer back to right after item1ptr
            item2ptr = item1ptr->getNext();     
            while (item2ptr != nullptr && inCount < size) {
                // item2ptr's data is less, so swap data and key
                if (item2ptr->getData() > item1ptr->getData())
                    swapItems(*item1ptr, *item2ptr);

                item2ptr = item2ptr->getNext(); // point to next item
                inCount++;
            }
            item1ptr = item1ptr->getNext(); // point to next item
            outCount++;
        }
        // prevent dangling pointers!
        item1ptr = nullptr;
        item2ptr = nullptr;
    }            

    // This helper function asdnkf;aowi
    void List::swapItems(ListItem& li1, ListItem& li2) {
        ListItem temp;      // for swapping

        temp = li2;
        li2 = li1;
        li1 = temp;
    }

    // displays list contents as linked list!
    void List::iterate() {
        ListItem* listPtr = headPtr;

        // iterate through to show data fields of items
        cout << "START->";
        while (listPtr != nullptr) {
            cout << listPtr->getData() << "->";
            listPtr = listPtr->getNext();
        }
        cout << "END\n";

        // iterate through again to show keys
        listPtr = headPtr;
        cout << "KEY:   ";
        while (listPtr != nullptr) {
            cout << "(" << listPtr->getDataKey() << ")  ";
            listPtr = listPtr->getNext();
        }
        cout << endl;

        listPtr = nullptr;
    }

    // This method iterates through list from head and deletes each item.
    void List::clearList() {
        // remove each item in list starting at head until list is empty
        while (headPtr != nullptr)
            removeHead();
    }

    // This method sets the iterator to the headPtr to keep track of item it is pointing to.
    // Then, it returns the data of the first item.
    List::listType List::start() {
        iterator = headPtr;
        return headPtr->getData();
    }

    // This method sets the iterator to the tailPtr to keep track of item it is pointing to.
    // Then, it returns the data of the last item.
    List::listType List::end() {
        iterator = tailPtr;
        return tailPtr->getData();
    }

    // This method returns the data of the item after the one iterator points to.
    // If there is no item, it returns dummy data.
    List::listType List::getNext() {
        listType data(-1.0);
        if (hasNext())
            return data;
        else {
            iterator = iterator->getNext();
            return iterator->getData();
        }
    }

    // This method returns whether or not the item iterator points to has an item after it.
    bool List::hasNext() const {
        return (iterator->getNext() != nullptr);
    }

    // This method searches for an item with a matching key and returns its data.
    List::listType List::getData(int key) {
        ListItem* item = find(key);
        return item->getData();
    }

    // This is a helper function for insert to tail and head methods, which 
    // adds new ListItem to list based on location of listPtr.
    void List::insert(const listType& entry, ListItem* listPtr) {
        ListItem* newItemPtr = new ListItem(entry); // new item has entry data

        newItemPtr->setKey(keyMkr++);   // set unique key of item

        // empty list case sets head and tail to new item
        if (headPtr == nullptr) {
            headPtr = newItemPtr;
            tailPtr = newItemPtr;
        }
        // insert to head case
        else if (listPtr == headPtr) {
            // link new item to old head, old head's to new, set head to new
            newItemPtr->setNext(headPtr);
            headPtr->setPrev(newItemPtr);
            headPtr = newItemPtr;
        }
        // insert to tail case
        else if (listPtr == tailPtr) {
            // link new item to old tail, old tail's to new, set tail to new
            newItemPtr->setPrev(tailPtr);
            tailPtr->setNext(newItemPtr);
            tailPtr = newItemPtr;
        }

        // increment listPtr and prevent a dangling pointer!
        size++;
        listPtr = nullptr;
        newItemPtr = nullptr;
    }

    // This helper function searches through list for an item with a matching key,
    // then returns a pointer to the item.
    ListItem* List::find(int key) {
        ListItem* listPtr = headPtr;    // start at beginning of list

        // iterate over all items in list until end reached or item found
        while (listPtr != nullptr) {
            if (listPtr->getDataKey() == key)
                return listPtr;

            listPtr = listPtr->getNext();   // move to next item in list
        }

        // this only executes if search failed
        listPtr = nullptr;
        return listPtr;
    }

    // Friend function: Overloaded outstream operator
    // Sends contents of Linked List to outstream
    // Assumes listType can be outputted to console (or has outstream capabilities) and
    // that listType has getData member function.
    ostream& operator<<(ostream& out, const List& l) {
        ListItem* listPtr = l.headPtr;

        // iterate through to show data fields of items
        out << "START->";
        while (listPtr != nullptr) {
            out << listPtr->getData() << "->";
            listPtr = listPtr->getNext();
        }
        out << "END\n";

        // iterate through again to show keys
        listPtr = l.headPtr;
        out << "KEY:   ";
        while (listPtr != nullptr) {
            out << "(" << listPtr->getDataKey() << ")  ";
            listPtr = listPtr->getNext();
        }
        out << endl;

        listPtr = nullptr;

        return out;
    }

    // This method generates stub program results of List methods to console to 
    // demonstrate class features.
    void List::GenStubResults() {
        cout << "LIST CLASS TEST REPORT\n\n"
             << "This displays the functionality of the List class, including constructor\n"
             << "use and methods using test data.\n\n";

        List::listType dc(0.7), dc1(1.1), dc2(2.4), dc3(3.5);

        List tList(dc);         // for testing

        cout << "Constructor Tests\n\n";
        cout << "Testing Parametrized constructor...\n";
        cout << "List initialized with data: " << dc << " inserted at start.\n";
        tList.iterate();

        cout << "Testing Copy constructor...\n";
        List t1List(tList);
        cout << "Showing copied list: \n";
        t1List.iterate();

        cout << "\nMethod Tests\n";
        cout << "Testing insertToHead() method...";
        tList.insertToHead(dc1);
        cout << "\nInserting " << dc1 << " to head...\n";
        tList.iterate();
    
        tList.insertToTail(dc2);
        cout << "\nTesting insertToTail() method...";
        cout << "\nInserting " << dc2 << " to tail...\n";
        // tList.iterate();

        tList.insertToMid(dc3);
        cout << "\nTesting insertToMid() method...";
        cout << "\nInserting " << dc3 << " to middle...\n";
        tList.iterate();

        tList.removeHead();
        cout << "\nTesting removeHead() method...\n";
        cout << "\nRemoved item at head.\n";
        tList.iterate();

        tList.removeTail();
        cout << "\nTesting removeTail() method...\n";
        cout << "\nRemoved item at tail\n";
        tList.iterate();

        tList.insertToMid(dc);
        cout << "\nInserting " << dc << " to middle...\n";
        tList.iterate();

        tList.insertToMid(dc1);
        cout << "\nInserting " << dc1 << " to middle...\n";
        tList.iterate();

        cout << "Testing getSize() method...\n";
        cout << "\nList size: " << tList.getSize() << endl;

        cout << "\nTesting search() method...\n";

        // look for keys from 0 to 3
        for (int i = 0; i < 4; i++) {
            cout << "Searching for key of " << i << ": "
                 << (tList.search(i) ? "found" : "not found") << endl;
        }

        cout << "Current list order: \n";
        tList.iterate();

        cout << "\nTesting sortAsc() method...\n";
        cout << "\nSorting in ascending order...\n";
        tList.sortAsc();
        tList.iterate();

        cout << "\nTesting sortDesc() method...\n";
        cout << "\nSorting in descending order...\n";
        tList.sortDesc();
        tList.iterate();

    }

    // This method generates a text file with name "Stub-Report" displaying stub program results to
    // demonstrate class features.
    void List::GenStubReport() {
        ofstream outFile;

        outFile.open("List-Stub-Report.txt");

        outFile << "LIST CLASS TEST REPORT\n\n"
             << "This displays the functionality of the List class, including constructor\n"
             << "use and methods using test data.\n\n";

        List::listType dc(0.7), dc1(1.1), dc2(2.4), dc3(3.5);

        List tList(dc);         // for testing

        outFile << "Constructor Tests\n\n";
        outFile << "Testing Parametrized constructor...\n";
        outFile << "List initialized with data: " << dc << " inserted at start.\n";
        outFile << tList << endl;

        outFile << "\nMethod Tests\n";
        outFile << "Testing insertToHead() method...";
        tList.insertToHead(dc1);
        outFile << "\nInserting " << dc1 << " to head...\n";
        outFile << tList << endl;
    
        tList.insertToTail(dc2);
        outFile << "\nTesting insertToTail() method...";
        outFile << "\nInserting " << dc2 << " to tail...\n";
        outFile << tList << endl;

        tList.insertToMid(dc3);
        outFile << "\nTesting insertToMid() method...";
        outFile << "\nInserting " << dc3 << " to middle...\n";
        outFile << tList << endl;

        tList.removeHead();
        outFile << "\nTesting removeHead() method...\n";
        outFile << "\nRemoved item at head.\n";
        outFile << tList << endl;

        tList.removeTail();
        outFile << "\nTesting removeTail() method...\n";
        outFile << "\nRemoved item at tail\n";
        outFile << tList << endl;

        tList.insertToMid(dc);
        outFile << "\nInserting " << dc << " to middle...\n";
        outFile << tList << endl;

        tList.insertToMid(dc1);
        outFile << "\nInserting " << dc1 << " to middle...\n";
        outFile << tList << endl;

        outFile << "Testing getSize() method...\n";
        outFile << "\nList size: " << tList.getSize() << endl;

        outFile << "\nTesting search() method...\n";

        // look for keys from 0 to 3
        for (int i = 0; i < 4; i++) {
            outFile << "Searching for key of " << i << ": "
                 << (tList.search(i) ? "found" : "not found") << endl;
        }

        outFile << "Current list order: \n";
        outFile << tList << endl;

        outFile << "\nTesting sortAsc() method...";
        outFile << "\nSorting in ascending order.\n";
        tList.sortAsc();
        outFile << tList << endl;

        outFile << "\nTesting sortDesc() method...";
        outFile << "\nSorting in descending order.\n";
        tList.sortDesc();
        outFile << tList << endl;

        outFile.close();
    }
}
