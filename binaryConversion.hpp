#ifndef BINARY_CONVERSION_HPP
#define BINARY_CONVERSION_HPP

#include <iostream>
#include <string>
#include <sstream>  // Added for stringstream
#include <iomanip>  // Added for hex manipulator

void displayBinaryConversionMenu();
void handleBinaryConversions();
std::string decimalToBinary(int num);
int binaryToDecimal(std::string binary);
std::string binaryToHex(std::string binary);
std::string hexToBinary(std::string hex);

#endif // BINARY_CONVERSION_HPP

