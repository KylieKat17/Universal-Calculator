// src/util.cpp
#include "util.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// ===================================================
//  STRING UTILITIES
// ===================================================

// Converts an entire string to lowercase
string toLowercase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(),
              [](unsigned char c) { return std::tolower(c); });
    return result;
}

// Trims leading and trailing whitespace from a string
string trimWhitespace(const string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end   = str.find_last_not_of(" \t\n\r");

    if (start == string::npos || end == string::npos)
        return "";

    return str.substr(start, end - start + 1);
}

// ===================================================
//  VALIDATION HELPERS
// ===================================================

// Checks if a string is a valid binary number (only 0 and 1)
bool isValidBinary(const string& str) {
    if (str.empty()) return false;
    return all_of(str.begin(), str.end(),
                  [](char c) { return c == '0' || c == '1'; });
}

// Checks if a string is a valid hexadecimal number
bool isValidHex(const string& str) {
    if (str.empty()) return false;
    return all_of(str.begin(), str.end(),
                  [](unsigned char c) { return std::isxdigit(c); });
}

// ===================================================
//  FORMATTING HELPERS
// ===================================================

// Pads a binary string with leading zeros to a given length
string padBinary(const string& binaryStr, size_t length) {
    if (binaryStr.size() >= length) return binaryStr;
    return string(length - binaryStr.size(), '0') + binaryStr;
}

// Function to trim excessive leading zeros while ensuring at least one leading zero
string trimLeadingZeros(const string& binary) {
    size_t firstOne = binary.find_first_not_of('0');
    if (firstOne == string::npos) {
        return "0"; // If all zeros, return a single zero
    }
    return "0" + binary.substr(firstOne);
}

// Formats a binary string into groups (default 4 bits)
string formatBinaryWithSpaces(const string& binaryStr, int groupSize) {
    string cleaned;
    for (char c : binaryStr) {
        if (c == '0' || c == '1')
            cleaned += c;
    }

    string result;
    int count = 0;
    for (size_t i = 0; i < cleaned.size(); ++i) {
        result += cleaned[i];
        count++;
        if (count == groupSize && i != cleaned.size() - 1) {
            result += ' ';
            count = 0;
        }
    }
    return result;
}

// Converts a decimal to uppercase hexadecimal string
string decimalToUpperHex(long long value) {
    stringstream ss;
    ss << uppercase << hex << value;
    return ss.str();
}

// ===================================================
//  USER PROMPTS & UX HELPERS
// ===================================================

// Asks user if they want to perform another operation
bool promptReturnToMenu() {
    string input;
    cout << "\nWould you like to perform another operation? (y/n): ";
    getline(cin >> ws, input);

    input = toLowercase(trimWhitespace(input));
    return (input == "y" || input == "yes");
}

// Asks user if they want to reset shift values (for bit shifting)
bool promptResetShift() {
    string input;
    cout << "\nWould you like to reset the shift values? (y/n): ";
    getline(cin >> ws, input);

    input = toLowercase(trimWhitespace(input));
    return (input == "y" || input == "yes");
}

// Prints a standard invalid input message
void printInvalidInputMessage() {
    cout << "\nInvalid input. Please try again.\n";
}

// ===================================================
//  BINARY & HEX CONVERSIONS
// ===================================================

// Function to convert decimal to binary with at least 8-bit padding
string decimalToBinary(int num) {
    if (num == 0) return "00000000";
    string binary = "";
    while (num > 0) {
        binary += (num % 2) + '0';
        num /= 2;
    }
    reverse(binary.begin(), binary.end());
    
    // Ensure at least 8-bit representation
    while (binary.size() < 8 || binary.size() % 4 != 0) {
        binary = '0' + binary;
    }
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(string& binary) {
    int decimal = 0;
    for (char bit : binary) {
        decimal = decimal * 2 + (bit - '0');
    }
    return decimal;
}

// Function to convert binary to hexadecimal
string binaryToHex(string& binary) {
    int decimal = binaryToDecimal(binary);
    stringstream ss;
    ss << hex << decimal;
    return ss.str();
}

// Function to convert hexadecimal to binary with at least 8-bit padding
string hexToBinary(string& hex) {
    int decimal;
    stringstream ss;
    ss << std::hex << hex;  // Convert hex string to decimal
    ss >> decimal;
    return decimalToBinary(decimal);  // Convert decimal to binary
}

// Function to convert a hexadecimal string to an integer
long long hexToDecimal(const string& hexStr) {
    long long decimalValue;
    stringstream ss;
    ss << std::hex << hexStr;
    ss >> decimalValue;
    return decimalValue;
}

// Function to convert an integer to a hexadecimal string
string decimalToHex(long long decimalValue) {
    stringstream ss;
    ss << std::hex << decimalValue;
    return ss.str();
}