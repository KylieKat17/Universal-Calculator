// include/util.hpp
#pragma once
#include <string>
#include <vector>

// Pads a binary string with leading 0s to match the desired length
std::string padBinary(const std::string& bin, size_t length);

// Converts a binary string to an unsigned integer
unsigned int binaryToUInt(const std::string& binary);

// Converts an unsigned integer to a binary string
std::string uintToBinary(unsigned int number, size_t minWidth = 0);

// Makes lowercase copy of a string
std::string toLower(const std::string& input);

// Splits a string on whitespace (if needed later)
std::vector<std::string> splitWhitespace(const std::string& input);
