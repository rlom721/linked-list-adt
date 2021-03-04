// Specification file for List class
//
// This List class is a linked list with methods to insert, sort, search, iterate
// through list.

#ifndef LIST_H
#define LIST_H

// #include "DataClass.h"    // header file for ListItem class
#include "ListItem.h"    // header file for ListItem class
#include <iostream>
namespace lomboy_a2 {

    // // forward-declare Iterator to be used by List ??
    // class Iterator;

    class List {
    public:
        // typedef
        typedef ListItem::listDataType listType;    // List depends on data type of ListItem
        // typedef ListItem* iterator;              // make iterator class??
        // typedef const ListItem* iterator;
        // typedef Iterator iterator;
        // Constructors
        List();
        List(listType data);
        // List(ListItem)        // may remove...
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
        // bool search(const listType& item);       // may delete...
        bool search(int key);
        void sortAsc();            // selection sort
        void sortDesc();
        void traverse();            // displays list contents as linked list!
        void clearList();
        // listType iterator();        // like a pointer for a list, but only ret data
        // listType getNext();        // get item after iterator()
        // bool hasNext();
        // Constant methods
        listType getFirstData() const { return headPtr->getData(); };
        listType getLastData() const { return tailPtr->getData(); };
        int getSize() const { return size; };
        bool isOrdered() const { return isSorted; };
        // listType start(); 
        // Overloaded Operators
        // List& operator=(const List& l);    // use deep copy
        // Friend functions
        friend class Iterator;
        friend std::ostream& operator<<(std::ostream& out, const List& l);
    private:
        // typedef
        typedef ListItem itemType;      // for iterator
        // Helper functions
        void insert(const listType&, ListItem*);
        ListItem* find(int key);
        // void sort(bool isAscending);            // selection sort
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
