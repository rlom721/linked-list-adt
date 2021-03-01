// DataClass.cpp
// implementation file for DataClass class

#include "DataClass.h"    // header file for DataClass class
#include <iostream>     
using namespace std;

// Default constructor uses default constructor of data type to set 
// default value for data
DataClass::DataClass() : data(dataType()) { }

// Parametrized constructor sets argument value for data
DataClass::DataClass(dataType data) : data(data) { }

// Copy constructor copies data value of another DataClass object
DataClass::DataClass(const DataClass& dc) {
  data = dc.data;
}

// This method sets data value based on argument provided.
// Assumes argument passed is an dataType.
void DataClass::set(dataType data) {
  this->data = data;
}

// Overloaded copy assignment 
// This copies data from another DataClass object.
DataClass& DataClass::operator=(const DataClass& dc){
  if (this != &dc) {
    data = dc.data;
  }

  return *this;
}

// ? Delete ?
// Friend function: Overloaded outstream operator
// Displays data of DataClass object
ostream& operator<<(ostream& out, const DataClass& dc) {
  out << "data: " << dc.get();

  return out;
}

// Friend function: Overloaded == operator
// Returns true if dc1 and dc2 have equal data fields.
bool operator==(const DataClass& dc1, const DataClass& dc2) {
  return (dc1.get() == dc2.get());
}
