// Specification file for List class
//
// This List class is a linked list with methods to insert, sort, search, iterate
// through list.

#ifndef LIST_H
#define LIST_H

#include "DataClass.h"    // header file for ListItem class
#include "ListItem.h"    // header file for ListItem class
// #include "List.h"       // header file for ListItem class
#include <iostream>
namespace lomboy_a2 {

    class List {
    public:
        // typedef
        typedef ListItem::listDataType listType;    // List depends on data type of ListItem
        // Constructors
        List();
        List(listType data);
        // List(ListItem)        // may remove...
        List(const List& l);    // use deep copy - do NOT copy pointers!
        // Destructor
        ~List();
        // Modification methods
        void insert(const listType&);       // default inserts new ListItem to tail
        void insertToHead(const listType&);
        // void insertToMid(listType);
        // void remove(listType);
        void removeHead();
        // bool search(listType);
        // void sortAsc();            // selection sort
        // void sortDesc();
        void traverse();            // displays list contents as linked list!
        void clearList();
        // listType iterator();        // like a pointer for a list, but only ret data
        // listType getNext();        // get item after iterator()
        // bool hasNext();
        // Constant methods
        bool isOrdered() const { return isSorted; };
        // listType start();
        // Overloaded Operators
        // List& operator=(const List& l);    // use deep copy
        // Friend functions
        friend std::ostream& operator<<(std::ostream& out, const List& l);
    private:
        // Member variables
        ListItem* headPtr;
        ListItem* tailPtr;
        int size;
        bool isSorted;
        int keyMkr;      // generate a key!
    };

}

#endif
