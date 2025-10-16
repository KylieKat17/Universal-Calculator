#ifndef BINARY_CALCULATOR_HPP
#define BINARY_CALCULATOR_HPP

#include <vector>
#include <string>

// Function Prototypes
void displayBinaryMenu(); // V2
void handleBinaryCalculations(); // V2
bool validateAndProcessOperation(char& operation);
std::string padBinary(std::string binary, size_t length); // moving to util files
std::string trimLeadingZeros(std::string binary);
std::string addBinary(std::string a, std::string b);
std::string subtractBinary(std::string a, std::string b);
std::string addMultipleBinaries(std::vector<std::string>& binaries);
std::string subtractMultipleBinaries(std::vector<std::string>& binaries);

#endif // BINARY_CALCULATOR_HPP