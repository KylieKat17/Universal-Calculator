#ifndef BINARY_CALCULATOR_H
#define BINARY_CALCULATOR_H

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

void displayBinaryMenu(); // V2
void handleBinaryCalculations(); // V2
std::string padBinary(std::string binary, size_t length);
std::string trimLeadingZeros(std::string binary);
std::string addBinary(std::string a, std::string b);
std::string subtractBinary(std::string a, std::string b);
std::string addMultipleBinaries(std::vector<std::string>& binaries);
std::string subtractMultipleBinaries(std::vector<std::string>& binaries);

#endif // BINARY_CALCULATOR_H