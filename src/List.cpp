
// #include "DataClass.h"    // header file for ListItem class
#include "List.h"        // header file for List class
#include "ListItem.h"    // header file for ListItem class
#include <iostream>
using namespace std;
namespace lomboy_a2 {

    // Default constructor sets default values of members
    List::List()
        : headPtr(nullptr), tailPtr(nullptr), size(0), isSorted(false), keyMkr(0) { }

    // Parametrized constructor sets default values of members, then inserts a new
    // entry into list.
    List::List(listType data)
        : headPtr(nullptr), tailPtr(nullptr), size(0), isSorted(false), keyMkr(0) {
        insertToTail(data);
    }

    // Copy constructor performs deep copy by copying data of elements into ListItems
    // of a NEW location (so pointers don't point to original)
    List::List(const List& l) {
        // for empty list
        if (l.headPtr == nullptr)
            return;
        // insert(l.start());   // copy data of first item of list ?? hmm iterators...
    }

    // Destructor frees allocated memory through list
    List::~List() {
        cout << "DESTRUCTOR!\n";
        clearList();
    }

    // This is a helper function for insert methods, which adds new ListItem to 
    // list based on location of listPtr.
    void List::insert(const listType& entry, ListItem* listPtr) {
        ListItem* newItemPtr = new ListItem(entry); // new item has entry data

        // empty list case sets head and tail to new item
        if (headPtr == nullptr) {
            newItemPtr->setKey(keyMkr++);   // set unique key of item
            headPtr = newItemPtr;
            tailPtr = newItemPtr;
        }
        // insert to head case
        else if (listPtr == headPtr) {
            newItemPtr->setKey(keyMkr++);   // set unique key of item

            // link new item to old head, old head's to new, set head to new
            newItemPtr->setNext(headPtr);
            headPtr->setPrev(newItemPtr);
            headPtr = newItemPtr;
        }
        // insert to tail case
        else if (listPtr == tailPtr) {
            newItemPtr->setKey(keyMkr++);   // set unique key of item

            // link new item to old tail, old tail's to new, set tail to new
            newItemPtr->setPrev(tailPtr);
            tailPtr->setNext(newItemPtr);
            tailPtr = newItemPtr;
        }
        // insert to middle case
        else {
            ListItem* nextItemPtr; // points to item AFTER listPtr
            nextItemPtr = listPtr->getNext();
            newItemPtr->setKey(keyMkr++);   // set unique key of item

            // link new item to listPtr and to next
            newItemPtr->setPrev(listPtr);
            newItemPtr->setNext(nextItemPtr);
            
            // link listPtr to new and next to new
            listPtr->setNext(newItemPtr);
            nextItemPtr->setPrev(newItemPtr);

            // to prevent dangling pointer!
            nextItemPtr = nullptr;
        }

        // increment listPtr and prevent a dangling pointer!
        size++;
        listPtr = nullptr;
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
        int item = 0;      // places to move in list

        while (item < (size / 2)) {
            listPtr = listPtr->getNext();
            item++;
        }

        // insert to middle location, after listPtr
        insert(entry, listPtr);

        listPtr = nullptr;
    }

    // This method deletes item at head.
    // Works for empty list and one list item cases.
    void List::removeHead() {
        // check for empty list OR list having one item
        if (size > 0) {
            ListItem* temp = headPtr;    // temporary used to delete item at head

            // set headPtr to item after the one to be deleted, set prev to nullptr
            headPtr = temp->getNext();

            // check if list has more than one item
            if (headPtr != nullptr)
                headPtr->setPrev(nullptr);
            else
                tailPtr = nullptr;

            // free dynamically-allocated ListItem (previous head)
            delete temp;
            size--;
        }
        else {
            std::cout << "List has no items.\n";
        }
    }

    bool List::search(int key) {
        // ListItem* listPtr = headPtr;    // to traverse through list

        // // loop over items in list - if matching key found, return true
        // while (listPtr != nullptr) {
        //     if (listPtr->getDataKey() == key)
        //         return true;

        //     listPtr = listPtr->getNext();   // to move to next item
        // }

        // return false;

        ListItem* itemPtr;      // to point to found item
        itemPtr = find(key);    // if found, returns pointer to item. if not, nullptr

        if (itemPtr != nullptr)
            return true;

        return false;                               
    }

    // displays list contents as linked list!
    void List::traverse() {
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
    // Displays contents of Linked List
    // Assumes listDataType can be outputted to console (or has outstream capabilities) and
    // that listDataType has getData member function.
    ostream& operator<<(ostream& out, const List& l){
        if (l.headPtr != nullptr && l.tailPtr != nullptr) {
            ListItem* listPtr = l.headPtr;

            while (listPtr != nullptr) {
                cout << "Item Data: " << *listPtr << endl;
                listPtr = listPtr->getNext();
            }

            cout << "END\n";

            out << "headPtr: " << l.headPtr->getData() << endl;
            out << "tailPtr: " << l.tailPtr->getData() << endl;
            out << "size: " << l.getSize() << endl;

            listPtr = nullptr;
        }
        else
            out << "headPtr and tailPtr are nullptr\n";

        return out;
    }

}
