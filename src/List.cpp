
// #include "DataClass.h"    // header file for ListItem class
#include "List.h"        // header file for List class
#include "ListItem.h"    // header file for ListItem class
#include <iostream>
using namespace std;
namespace lomboy_a2 {

    // Default constructor sets default values of members
    List::List()
        : headPtr(nullptr), tailPtr(nullptr), size(0), isSorted(false), keyMkr(0)
        { }

    // Parametrized constructor sets default values of members, then inserts a new
    // entry into list.
    List::List(listType data)
        : headPtr(nullptr), tailPtr(nullptr), size(0), isSorted(false), keyMkr(0) {
        insert(data);
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

    // This is the default insert method, which adds new ListItem to tail of list.
    void List::insert(const listType& entry) {
        ListItem* newItemPtr = new ListItem(entry); // new item has entry data

        // check for empty list
        if (headPtr != nullptr) {
            // link new item to old tail, set old tail's next to new,
            newItemPtr->setPrev(tailPtr);
            tailPtr->setNext(newItemPtr);
        }
        else {
            headPtr = newItemPtr;
        }
        // set tail to new
        tailPtr = newItemPtr;
        size++;
    }

    // This is insert method adds new ListItem to head of list.
    void List::insertToHead(const listType& entry) {
        ListItem* newItemPtr = new ListItem(entry); // new item has entry data

        // check for empty list
        if (headPtr != nullptr) {
            // link new item to old head, set old head's next to new,
            newItemPtr->setNext(headPtr);
            headPtr->setPrev(newItemPtr);
        }
        else {
            headPtr = newItemPtr;
        }
        // set head to new
        headPtr = newItemPtr;
        size++;
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

    // // This method deletes item from tail.
    // void List::removeTail() {
    //     // check for empty list
    //     if (size != 0) {
    //         ListItem* temp = tailPtr;       // temporary to delete item at tail

    //         // set tailPtr to item before the one to be deleted, set next field to null
    //         tailPtr = temp->getPrev();
    //         tailPtr->setNext(nullptr);

    //         delete temp;    // free dynamically-allocated ListItem (previous tail)
    //         size--;         // list is one item smaller
    //     }
    //     else {
    //         std::cout << "List has no items.\n";
    //     }
    // }

    // // This method deletes item from list with data matching the argument.
    // void List::remove(listType data) {

    // }

    // displays list contents as linked list!
    void List::traverse() {
        ListItem* listPtr = headPtr;

        while (listPtr != nullptr) {
            // cout << "(" << listPtr->getDataKey() << ") "
            cout << listPtr->getData() << "->";
            listPtr = listPtr->getNext();
        }
        cout << "END\n";

        listPtr = nullptr;
    }

    // This method iterates through list from head and deletes each item.
    void List::clearList() {
        // remove each item in list starting at head until list is empty
        while (headPtr != nullptr)
            removeHead();
    }

    // Friend function: Overloaded outstream operator
    // Displays contents of Linked List

    // Assumes listDataType can be outputted to console (or has outstream capabilities) and
    // that listDataType has getData member function.
    ostream& operator<<(ostream& out, const List& l){
        if (l.headPtr != nullptr && l.tailPtr != nullptr) {
            out << "headPtr: " << l.headPtr->getData() << endl;
            out << "tailPtr: " << l.tailPtr->getData() << endl;
        }
        else
            out << "headPtr and tailPtr are nullptr\n";

        return out;
    }

}
