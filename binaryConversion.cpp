#include "binaryConversion.h"
#include <algorithm>

using namespace std;

// Function to convert decimal to binary
string decimalToBinary(int num) {
    if (num == 0) return "0";
    string binary = "";
    while (num > 0) {
        binary += (num % 2) + '0';
        num /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    for (char bit : binary) {
        decimal = decimal * 2 + (bit - '0');
    }
    return decimal;
}

// Function to convert binary to hexadecimal
string binaryToHex(string binary) {
    int decimal = binaryToDecimal(binary);
    stringstream ss;
    ss << hex << decimal;
    return ss.str();
}

// Function to convert hexadecimal to binary
string hexToBinary(string hex) {
    int decimal;
    stringstream ss;
    ss << std::hex << hex;  // Convert hex string to decimal
    ss >> decimal;
    return decimalToBinary(decimal);  // Convert decimal to binary
}
