#ifndef BITSHIFT_HPP
#define BITSHIFT_HPP

#include <iostream>
#include <bitset>
#include <limits>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Function prototypes
void handleBitShifting();
void displayBitShiftMenu();
string logicalLeftShift(const string&, int);
string logicalRightShift(const string&, int);
string arithmeticRightShift(const string&, int);
void performAllShifts(const string&, int);

#endif //BITSHIFT_HPP
