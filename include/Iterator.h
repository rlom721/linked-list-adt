// Specification file for Iterator class
//

#ifndef ITERATOR_H
#define ITERATOR_H

#include "List.h"
namespace lomboy_a2 {

    class Iterator {
    public:
        // Constructors
        Iterator();
        Iterator(itemType* start);
        Iterator(const Iterator&);
        // Modification methods
        // Costant methods
        // Overloaded operators
    private:
        // typedef
        typedef List::itemType itemType;
        // member variables
        itemType* currentPtr;
    }

}

#endif