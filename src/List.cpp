// Implementation file for List class
// File name: List.cpp

#include "List.h"        // header file for List class
#include "ListItem.h"    // header file for ListItem class
#include <iostream>
#include <new>           // for bad_alloc for isFull method
using namespace std;
namespace lomboy_a2 {

    // Default constructor sets default values of members
    List::List()
        : headPtr(nullptr), tailPtr(nullptr), size(0), keyMkr(0) { 
    }

    // Parametrized constructor sets default values of members, then inserts a new
    // entry into list.
    List::List(listType data)
        : headPtr(nullptr), tailPtr(nullptr), size(0), keyMkr(0) {
        insertToTail(data);
    }

    // Copy constructor performs deep copy by copying data of elements into ListItems
    // of a NEW location (so pointers don't point to original)
    List::List(const List& l) {
        // initialize variables of THIS list
        headPtr = nullptr;
        tailPtr = nullptr;
        size = 0;
        keyMkr = 0;

        ListItem* listPtr = l.headPtr;    // to iterate through list
        listType entryCopy;               // to add data to new list
        
        // for empty list
        if (l.headPtr == nullptr)
            return;

        // iterate through to copy item data into new list
        while (listPtr != nullptr) {
            entryCopy = listPtr->getData();
            this->insertCopy(entryCopy);
            listPtr = listPtr->getNext();
        }

        // avoid dangling pointer
        listPtr = nullptr;
    }

    // Destructor frees allocated memory through list
    List::~List() {
        clearList();
    }

    // This is insert method adds new ListItem to head of list.
    void List::insertToHead(const listType& entry) {
        // check if there is space to allocate - otherwise, exception is thrown
        if (canAllocate()) {

            ListItem* newItemPtr = new ListItem(entry); // new item has entry data

            newItemPtr->setKey(keyMkr++);   // set unique key of item

            // empty list case sets head and tail to new item
            if (headPtr == nullptr) {
                headPtr = newItemPtr;
                tailPtr = newItemPtr;
            }
            // insert to head
            else {
                // link new item to old head, old head's to new, set head to new
                newItemPtr->setNext(headPtr);
                headPtr->setPrev(newItemPtr);
                headPtr = newItemPtr;
            }

            // increment listPtr and prevent a dangling pointer!
            size++;
            newItemPtr = nullptr;
        }
    }

    // This is insert method adds new ListItem to tail of list.
    void List::insertToTail(const listType& entry) {
        // check if there is space to allocate - otherwise, exception is thrown
        if (canAllocate()) {
            ListItem* newItemPtr = new ListItem(entry); // new item has entry data

            newItemPtr->setKey(keyMkr++);   // set unique key of item

            // empty list case sets head and tail to new item
            if (headPtr == nullptr) {
                headPtr = newItemPtr;
                tailPtr = newItemPtr;
            }
            // insert to tail
            else {
                // link new item to old tail, old tail's to new, set tail to new
                newItemPtr->setPrev(tailPtr);
                tailPtr->setNext(newItemPtr);
                tailPtr = newItemPtr;
            }

            // increment listPtr and prevent a dangling pointer!
            size++;
            newItemPtr = nullptr;
        }
    }

    // This is insert method adds new ListItem to middle of list.
    void List::insertToMid(const listType& entry) {
        // check if there is space to allocate - otherwise, exception is thrown
        if (canAllocate()) {
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

    // This helper function swaps two ListItems in the list (only their data).
    void List::swapItems(ListItem& li1, ListItem& li2) {
        ListItem temp;      // for swapping

        temp = li2;
        li2 = li1;
        li1 = temp;
    }

    // This method displays list contents as linked list!
    void List::iterate() {
        iterator it = start();
        

        // iterate through to show data fields of items
        cout << "START->";
        while (it.hasNext()) {
            cout << *it << "->";
            ++it;
        }
        cout << "END\n";

        // iterate through again to show keys
        ListItem* listPtr = headPtr;

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

    // This method returns an iterator  the iterator to the headPtr to keep track of item it is pointing to.
    // Then, it returns the data of the first item.
    List::iterator List::start() const {
        return iterator(headPtr);
    }

    // This method sets the iterator to the tailPtr to keep track of item it is pointing to.
    // Then, it returns the data of the last item.
    List::iterator List::end() const {
        return iterator(tailPtr);
    }

    // This method searches for an item with a matching key and returns its data.
    // returns dummy data if invalid index
    List::listType List::getData(int key) {
        ListItem* item = find(key);
        
        if (item == nullptr) {
            listType dummyData(-1.0);
            cout << "No item with key found.\n";
            return dummyData;
        }
        else 
            return item->getData();
    }

    // This method returns true if there is no space to allocate a new item.
    // It also throws an exception to indicate a bad_alloc.
    bool List::canAllocate() const { 
        bool hasSpace = false;

        try {
            ListItem* testItem = new ListItem;   // test item to check space

            // delete allocated memory (will occur if there is no exception thrown)
            delete testItem;
            testItem = nullptr;
            hasSpace = true;
        }
        catch (bad_alloc& ba) {
            cerr << "Not enought memory to allocate new item. bad_alloc caught: "
                 << ba.what() << '\n';
        }

        return hasSpace;
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

    // This healper method adds new ListItem to tail of list WITHOUT changing key.
    // To be used with copy constructor.
    void List::insertCopy(const listType& entry) {
        ListItem* newItemPtr = new ListItem(entry); // new item has entry data

        // empty list case sets head and tail to new item
        if (headPtr == nullptr) {
            headPtr = newItemPtr;
            tailPtr = newItemPtr;
        }
        // insert to tail
        else {
            // link new item to old tail, old tail's to new, set tail to new
            newItemPtr->setPrev(tailPtr);
            tailPtr->setNext(newItemPtr);
            tailPtr = newItemPtr;
        }

        // increment listPtr and prevent a dangling pointer!
        size++;
        newItemPtr = nullptr;
    }

    // Friend function: Overloaded outstream operator
    // Sends contents of Linked List to outstream (same output as iterate())
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

    // Default constructor for List's iterator class 
    List::iterator::iterator() : currentPtr(nullptr), itemNum(0) { }

    // Parameterized constructor for iterator class sets currentPtr to argument
    List::iterator::iterator(itemType* start) : currentPtr(start), itemNum(0) { }

    // copy constructor copies pointers!
    List::iterator::iterator(const iterator& it) { 
        currentPtr = it.currentPtr; 
        itemNum = it.itemNum;
    }

    // returns true if item has an item after it
    bool List::iterator::hasNext() const { return currentPtr; }

    // Moves iterator to next item then returns next item data
    List::iterator::itemData List::iterator::getNext() {
        currentPtr = currentPtr->getNext();
        itemNum++;

        return currentPtr->getData();
    }

    // Overloaded copy assignment checks if same object, then returns it
    List::iterator& List::iterator::operator=(const iterator& it) {
        // check if same object
        if (this != &it) {
            currentPtr = it.currentPtr;
            itemNum = it.itemNum;
        }
        return *this;
    }

    // Overloaded dereference operator to display data of current item being pointed to
    // To be used like dereferencing a pointer: *ptr
    List::iterator::itemData List::iterator::operator*() const { 
        return currentPtr->getData(); 
    }

    // Overloaded prefix increment operator to move to next item
    List::iterator& List::iterator::operator++() { 
        if (currentPtr != nullptr) {
            currentPtr = currentPtr->getNext(); 
            itemNum++;
        }

        return *this;
    }

    // Overloaded prefix decrement operator to go to previous item
    List::iterator& List::iterator::operator--() { 
        if (currentPtr != nullptr)
            currentPtr = currentPtr->getPrev(); 
        return *this;
    }

    // Friend function: Overloaded != operator
    // Returns true if it1 and it2 do NOT point to same spot in memory.
    bool operator!=(const List::iterator& it1, const List::iterator& it2) {
        return it1.currentPtr != it2.currentPtr;
    }

    // Friend function: Overloaded == operator
    // Returns true if it1 and it2 point to same spot in memory.
    bool operator==(const List::iterator& it1, const List::iterator& it2) {
        return it1.currentPtr == it2.currentPtr;
    }
}
