#include "UnitTester.h"
#include <iostream>
#include <string>
using namespace std;

const string UnitTester::RED = "\033[1;31m";  // color text bold red
const string UnitTester::GRN = "\033[1;32m";  // color text bold green
const string UnitTester::BLU = "\033[1;34m";  // color text bold blue
const string UnitTester::UL = "\033[4;37m";   // underlines white text
const string UnitTester::RST = "\033[0m";     // reset to default text settings

UnitTester::UnitTester() : className("Your") { }

UnitTester::UnitTester(string str) : className(str) { }

// FIX if msg is > WIDTH
void UnitTester::tEqual(string msg, int cVal, int tVal) {
// This method performs equality tests on ints (can take boolean too).
// msg = test message, cVal = correct value to compare, tVal = test value

  int msgLen = msg.length();    // length of message
  string testRes,               // pass or fail test result and labels
         testP = GRN + "Pass" + RST,
         testF = RED + "Fail" + RST;

  // label for test
  cout << msg << string(WIDTH - msgLen, '.');

  // test equality and print result
  testRes = (tVal == cVal) ? testP : testF;
  cout << testRes << endl;
}

void UnitTester::tEqual(string msg, double cVal, double tVal) {
// This method performs equality tests on doubles.
// msg = test message, cVal = correct value to compare, tVal = test value

  int msgLen = msg.length();    // length of message
  string testRes,               // pass or fail test result and labels
         testP = GRN + "Pass" + RST,
         testF = RED + "Fail" + RST;

  // label for test
  cout << msg << string(WIDTH - msgLen, '.');

  // test equality and print result
  testRes = (tVal == cVal) ? testP : testF;
  cout << testRes << endl;
}

void UnitTester::tEqual(string msg, string cStr, string tStr) {
// This method performs equality tests (msg = display test message,
// cStr = correct value to compare, tStr = test value).

  int msgLen = msg.length();    // length of message
  string testRes,               // pass or fail test result and labels
         testP = GRN + "Pass" + RST,
         testF = RED + "Fail" + RST;

  // label for test
  cout << msg << string(WIDTH - msgLen, '.');

  // test equality and print result
  testRes = (tStr == cStr) ? testP : testF;
  cout << testRes << endl;
}

void UnitTester::title() const {
// Prints out title/header for overall test (uses either default or constructor
// value for title).
  cout << BLU << "\n--- Testing " + className + " class ---\n\n" << RST;
}

void UnitTester::title(string str) {
// Takes string argument and prints out title/header for overall test.
  cout << BLU << "\n--- Testing " + str + " class ---\n\n" << RST;
}

void UnitTester::subTitle(string str) const {
// Prints out title for using entered string (usually for labelling  subtests
// of one method, or pass/fail testing).
  cout << UL << str << RST << endl;
}

void UnitTester::classTest() {

  UnitTester ut("UnitTester"); // for performing equality tests

  ut.title();

  // testing if tEqual method shows pass
  ut.subTitle("Passing Tests");
  ut.tEqual("tEqual(str, int, int)", 4, 4);
  ut.tEqual("tEqual(str, str, str)", "korra", "korra");

  // testing if tEqual method shows fail
  ut.subTitle("\nFailing Tests (these should fail!)");
  ut.tEqual("tEqual(str, int, int)", 4, 5);
  ut.tEqual("tEqual(str, str, str)", "avatar", "korra");
}