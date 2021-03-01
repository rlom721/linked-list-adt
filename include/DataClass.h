// Specification file for DataClass class
//
// This DataClass class contains a data member which can be set using
// methods and constructors.

#ifndef DATACLASS_H
#define DATACLASS_H

#include <iostream>

class DataClass {
public:
    typedef double dataType;       // data type DataClass contains
    // constructors
    DataClass();                    // default
    DataClass(dataType data);       // parametrized
    DataClass(const DataClass& dc); // copy
    // modification methods
    void set(dataType data);
    // constant methods
    dataType get() const { return data; }
    // overloaded operators
    DataClass& operator=(const DataClass& dc);
    // friend functions
    friend std::ostream& operator<<(std::ostream& out, const DataClass& dc);
    friend bool operator==(const DataClass& dc1, const DataClass& dc2);
private:
    // member variables
    dataType data;
};

#endif