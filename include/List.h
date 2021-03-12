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
        // public member variables
        const ListItem* iterator;
        // typedef
        typedef ListItem::listDataType listType;    // List depends on data type of ListItem
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
        void sortAsc();            // uses selection sort
        void sortDesc();
        void iterate();            // displays list contents to console as linked list!
        listType start(); 
        listType end();
        listType getNext();        
        bool hasNext() const;
        // Constant methods
        listType getData(int key);
        int getSize() const { return size; };
        // Friend functions and classes
        friend std::ostream& operator<<(std::ostream& out, const List& l);
    private:
        // Helper functions
        void clearList();
        ListItem* find(int key);
        void swapItems(ListItem& li1, ListItem& li2);
        void insertCopy(const listType& entry);
        // Member variables
        ListItem* headPtr;
        ListItem* tailPtr;
        int size;
        int keyMkr;             // generate a unique key for list item
    };

}

#endif
