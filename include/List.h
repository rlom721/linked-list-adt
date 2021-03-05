// Specification file for List class
//
// This List class is a linked list with methods to insert, sort, search, iterate
// through list.

#ifndef LIST_H
#define LIST_H

#include "ListItem.h"    // header file for ListItem class
#include <iostream>
namespace lomboy_a2 {

    class List {
    public:
        // typedef
        typedef ListItem itemType;      // for iterator
        typedef ListItem::listDataType listType;    // List depends on data type of ListItem
        // typedef Iterator iterator;      // so user can instantiate like: List::iterator
        // Constructors
        List();
        List(listType data);
        List(const List& l);    // use deep copy - do NOT copy pointers!
        // Destructor
        ~List();
        // Modification methods
        void insertToHead(const listType& entry);
        void insertToTail(const listType& entry);
        void insertToMid(const listType& entry);
        void remove(int key);
        void removeHead();
        void removeTail();
        bool search(int key);
        void sortAsc();            // selection sort
        void sortDesc();
        void iterate();            // displays list contents as linked list!
        void clearList();
        // Iterator start();
        // Iterator end();
        // listType getNext();        // get item after iterator()
        // bool hasNext();
        void GenStubResults();      // shows functionality of List class
        void GenStubReport();
        // Constant methods
        listType getFirstData() const { return headPtr->getData(); };
        listType getLastData() const { return tailPtr->getData(); };
        listType getData(int key);
        int getSize() const { return size; };
        bool isOrdered() const { return isSorted; };
        // Overloaded Operators
        // List& operator=(const List& l);    // use deep copy
        // Friend functions and classes
        friend std::ostream& operator<<(std::ostream& out, const List& l);
    private:
        // Helper functions
        void insert(const listType&, ListItem*);
        ListItem* find(int key);
        void swapItems(ListItem& li1, ListItem& li2);
        // Member variables
        ListItem* headPtr;
        ListItem* tailPtr;
        int size;
        bool isSorted;
        int keyMkr;             // generate a unique key for list item
    };

}

#endif
