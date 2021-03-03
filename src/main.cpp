#include <iostream>
#include "UnitTester.h"
#include "DataClass.h"
#include "ListItem.h"
#include "List.h"
using namespace std;
using namespace lomboy_a2;

int main () {
    // UnitTester ut;          // performs unit testing on classes
    // DataClass dc, dc1(2.7);
    // DataClass dc2 = dc1;    // set dc2 data to dc1 data
    //
    // // TEST DataClass Class ------------------------------------
    // ut.title("DataClass");
    //
    // ut.subTitle("Testing Constructors");
    // ut.tEqual("Default", 0.0, dc.get());
    // ut.tEqual("Parametrized", 2.7, dc1.get());
    // ut.tEqual("Copy", dc1.get(), dc2.get());
    //
    // dc.set(4.2);
    // ut.subTitle("\nTesting Setter Methods");
    // ut.tEqual("set(dataType)", 4.2, dc.get());
    //
    // dc = dc2;       // set dc data to dc2 data
    // dc1.set(1.1);
    // ut.subTitle("\nTesting Overloaded Operators");
    // ut.tEqual("Copy Assignment (=)", dc2.get(), dc.get());
    // ut.tEqual("Less Than (<)", true, dc1 < dc2);
    // ut.tEqual("Greater Than (>)", true, dc2 > dc1);
    //
    // cout << "Overloaded Outstream Output:\n" << dc << endl;
    //
    // // TEST ListItem Class -------------------------------------
    // ListItem li, li1(dc), li2(dc, &li1);
    //
    // ut.title("ListItem");
    // ut.subTitle("Testing Constructors");
    // ut.tEqual("Default - Data Init", true, li.getData() == 0.0);  // test listDataType()
    // ut.tEqual("Default - Ptr Init", true,
    //           (li.getNext() == nullptr) && (li.getPrev() == nullptr));
    // ut.tEqual("Param (listDataType) - Data Init", true, li1.getData() == dc.get());
    // ut.tEqual("Param (listDataType) - Ptr Init", true,
    //           (li1.getNext() == nullptr) && (li1.getPrev() == nullptr));
    //
    // // Note: Parametrized Constructor (listDataType, ListItem*) will be used with List ADT
    // ut.tEqual("Param (listDataType, ListItem*) - Data Init", true,
    //           li2.getData() == dc.get());
    // ut.tEqual("Param (listDataType, ListItem*) - Ptr Init", true,
    //           (li2.getNext() == &li1) && (li2.getPrev() == nullptr));
    //
    // ListItem li3(li2);
    // ut.tEqual("Copy - Data Init", true, li2.getData() == dc);
    // ut.tEqual("Copy - Ptr Init", true, (li3.getNext() == nullptr) && (li2.getPrev() == nullptr));
    //
    // // creating "List" with ListItem methods only! ---------------------------
    // DataClass d(1.1), d1(2.1), d2(3.1), d3(4.1);
    //
    // li.set(d);
    // li1.set(d1);
    // li2.set(d2);
    // li3.set(d3);
    //
    // // create linked list!
    // li.setNext(&li1);
    // li1.setPrev(&li);
    // li1.setNext(&li2);
    // li2.setPrev(&li1);
    // li2.setNext(&li3);
    // li3.setPrev(&li2);
    // li3.setNext(nullptr);
    //
    // // List Visualization!
    // cout << "\nli\n" <<  li;
    // cout << "\nli1\n" <<  li1;
    // cout << "\nli2\n" <<  li2;
    // cout << "\nli3\n" <<  li3;

    cout << "LIST CLASS\n";

    DataClass dc(0.7), dc1(1.1), dc2(2.4), dc3(3.5);

    List tList(dc);
    // cout << tList << endl;
    cout << "tList init with data: " << dc << endl;

    tList.insertToHead(dc1);
    cout << "Inserted to head\n";
    tList.traverse();
    cout << endl;

    tList.insertToTail(dc2);
    cout << "Inserted to tail\n";
    tList.traverse();
    cout << endl;

    tList.insertToMid(dc3);
    cout << "Inserted to mid\n";
    tList.traverse();
    cout << endl;

    tList.removeHead();
    cout << "Removed head\n";
    tList.traverse();
    cout << endl;

    tList.removeHead();
    cout << "Removed head\n";
    tList.traverse();
    cout << endl;

    tList.insertToMid(dc);
    cout << "Inserted to mid\n";
    tList.traverse();
    cout << endl;

    tList.removeTail();
    cout << "Removed tail\n";
    tList.traverse();
    cout << endl;

    tList.insertToMid(dc1);
    cout << "Inserted to mid\n";
    tList.traverse();
    cout << endl;

    // tList.insertToMid(dc2);
    // cout << "Inserted to mid\n";
    // tList.traverse();
    // cout << endl;
    cout << "List size: " << tList.getSize() << endl;

    cout << "Testing search method:\n";
    cout << "Looking for key of 0... " << tList.search(0) << endl;
    cout << "Looking for key of 4... " << tList.search(4) << endl;
    cout << "Looking for key of 7... " << tList.search(7) << endl;
    cout << "Looking for key of 3... " << tList.search(3) << endl;
    cout << "Looking for key of 2... " << tList.search(2) << endl;

    cout << "Sorting in ascending order...\n";
    tList.traverse();
    tList.sortAsc();
    tList.traverse();

    cout << "\nSorting in descending order...\n";
    tList.traverse();
    tList.sortDesc();
    tList.traverse();

    // cout << tList << endl;

    // List t2List(dc);

    // cout << t2List << endl;
    // t2List.insertToTail(dc1);
    // cout << t2List << endl;

    return 0;
}
