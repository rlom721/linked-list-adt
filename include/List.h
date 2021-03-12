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
        // forward declaration
        class iterator;
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
        // Constant methods
        iterator start() const; 
        iterator end() const;
        listType getData(int key);
        int getSize() const { return size; };
        // Friend functions and classes
        friend std::ostream& operator<<(std::ostream& out, const List& l);
        // Nested class (is also implicitly a friend)
        class iterator {
            // friend classes/classes
            friend class List;
            // typedef
            typedef ListItem itemType;  // iterator points to this type
            typedef List::listType itemData;  // iterator points to this type
        public:
            // Constructors
            iterator();
            iterator(itemType* start);
            iterator(const iterator& it);
            // Modification methods
            itemData getNext();
            // Constant methods
            bool hasNext() const;
            itemData operator*() const;
            // Overloaded operators
            iterator& operator=(const iterator& it);
            iterator& operator++();     // prefix increment
            iterator& operator--();     // prefix decrement
            // Friend functions
            friend bool operator!=(const iterator& it1, const iterator& it2);
            friend bool operator==(const iterator& it1, const iterator& it2);
        private:
            const itemType* currentPtr;
            int itemNum;
        };
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
