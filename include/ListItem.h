// Specification file for ListItem class
//
// This ListItem class represents an item (or node) of a linked list.

#ifndef LISTITEM_H
#define LISTITEM_H

#include "DataClass.h"    // header file for ListItem class
#include <iostream>
namespace lomboy_a2 {

    class ListItem {
    public:
        // typedef
        typedef DataClass listDataType;   // type of data/class list item holds
        // constructors
        ListItem();                   // default
        ListItem(listDataType ldt);   // parametrized
        ListItem(listDataType ldt, ListItem* nextItem); // parametrized (may remove...)
        ListItem(const ListItem& li); // copy
        // destructor
        // ~ListItem();    // no need?
        // modification methods
        void set(const listDataType& ldt);
        void setKey(int key);
        // void setKey(const listDataType& ldt);  // no need?
        void setNext(ListItem* nextPtr);
        void setPrev(ListItem* prevPtr);
        ListItem* getNext() { return nextPtr; }
        ListItem* getPrev() { return prevPtr; }        
        // constant methods
        listDataType getData() const { return data; }
        int getDataKey() const { return data.getKey(); }
        // overloaded operators
        ListItem& operator=(const ListItem& li);
        // friend function
        friend std::ostream& operator<<(std::ostream& out, const ListItem& li);
    private:
        // member variables
        listDataType data;
        ListItem* nextPtr;
        ListItem* prevPtr;
    };

}

#endif
