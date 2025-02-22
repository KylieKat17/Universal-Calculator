#ifndef BINARY_CONVERSION_H
#define BINARY_CONVERSION_H

#include <string>
#include <sstream>  // Added for stringstream
#include <iomanip>  // Added for hex manipulator

std::string decimalToBinary(int num);
int binaryToDecimal(std::string binary);
std::string binaryToHex(std::string binary);
std::string hexToBinary(std::string hex);

#endif // BINARY_CONVERSION_H
