#ifndef UNITTESTER_H
#define UNITTESTER_H

#include <iostream>
#include <string>

// This class performs equality testing on other classes!
class UnitTester {
private:
  static const int WIDTH = 50;    // char width to display on console
  static const std::string RED, GRN, BLU,  // change text color and bold
                      UL,         // underlines white text
                      RST;        // reset to default color
  std::string className;      // name of class being tested
public:
  UnitTester();
  UnitTester(std::string str);
  static void tEqual(std::string msg, int cVal, int tVal);
  static void tEqual(std::string msg, double cVal, double tVal);
  static void tEqual(std::string msg, std::string cVal, std::string tVal);
  void title() const;
  void title(std::string str);
  void subTitle(std::string str) const;
  void classTest();
};

#endif