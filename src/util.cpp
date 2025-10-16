// src/util.cpp
#include "util.hpp"
#include <algorithm>
#include <sstream>
#include <bitset>

std::string padBinary(const std::string& bin, size_t length) {
    if (bin.length() >= length) return bin;
    return std::string(length - bin.length(), '0') + bin;
}

unsigned int binaryToUInt(const std::string& binary) {
    return std::stoul(binary, nullptr, 2);
}

std::string uintToBinary(unsigned int number, size_t minWidth) {
    std::string result = std::bitset<64>(number).to_string(); // max 64 bits
    auto firstOne = result.find('1');
    if (firstOne == std::string::npos) return "0";

    std::string trimmed = result.substr(firstOne);
    if (trimmed.length() < minWidth)
        return std::string(minWidth - trimmed.length(), '0') + trimmed;
    return trimmed;
}

std::string toLower(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::vector<std::string> splitWhitespace(const std::string& input) {
    std::stringstream ss(input);
    std::string token;
    std::vector<std::string> results;

    while (ss >> token) {
        results.push_back(token);
    }

    return results;
}

