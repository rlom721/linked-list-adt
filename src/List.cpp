
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

        // // check for empty list OR list having one item
        // if (size > 0) {
        //     ListItem* temp = headPtr;    // temporary used to delete item at head

        //     // set headPtr to item after the one to be deleted, set prev to nullptr
        //     headPtr = temp->getNext();

        //     // check if list has more than one item
        //     if (headPtr != nullptr)
        //         headPtr->setPrev(nullptr);
        //     else
        //         tailPtr = nullptr;

        //     // free dynamically-allocated ListItem (previous head)
        //     delete temp;
        //     size--;
        // }
        // else {
        //     std::cout << "List has no items.\n";
        // }
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
        ListItem* item1ptr = headPtr;             // traverse through inner loop
        ListItem* item2ptr = headPtr->getNext();  // traverse through outer loop
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
        ListItem* item1ptr = headPtr;             // traverse through inner loop
        ListItem* item2ptr = headPtr->getNext();  // traverse through outer loop
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
            cout << "Inserting to head...\n";

            // link new item to old head, old head's to new, set head to new
            newItemPtr->setNext(headPtr);
            headPtr->setPrev(newItemPtr);
            headPtr = newItemPtr;
        }
        // insert to tail case
        else if (listPtr == tailPtr) {
            cout << "Inserting to tail...\n";

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
