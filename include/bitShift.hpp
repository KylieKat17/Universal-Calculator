#ifndef BIT_SHIFT_HPP
#define BIT_SHIFT_HPP

#include <bitset>
//#include <limits> Old, might need again
#include <string>

// Function prototypes
void handleBitShifting();
void displayBitShiftMenu();
std::string logicalLeftShift(const std::string&, int);
std::string logicalRightShift(const std::string&, int);
std::string arithmeticRightShift(const std::string&, int);
void performAllShifts(const std::string&, int);

#endif //BIT_SHIFT_HPP
