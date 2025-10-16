// include/util.hpp
#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>
#include <vector>

std::string toLowercase(const std::string& str);
std::string trimWhitespace(const std::string& str);
std::string formatBinaryWithSpaces(const std::string& binaryStr, int groupSize = 4);
std::string padBinary(const std::string& binaryStr, size_t length);
std::string trimLeadingZeros(const std::string& binary);
std::string decimalToUpperHex(long long value);

bool isValidBinary(const std::string& str);
bool isValidHex(const std::string& str);
bool promptReturnToMenu();
bool promptResetShift();
void printInvalidInputMessage();

#endif // UTIL_HPP