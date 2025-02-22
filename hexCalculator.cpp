#include "hexCalculator.h"
#include "hexConversion.h"
#include <iostream>
#include <vector>

using namespace std;

// Function to add two hexadecimal numbers
string addHex(string a, string b) {
    long long decimalA = hexToDecimal(a);
    long long decimalB = hexToDecimal(b);
    long long sum = decimalA + decimalB;
    return decimalToHex(sum);
}

// Function to subtract two hexadecimal numbers
string subtractHex(string a, string b) {
    long long decimalA = hexToDecimal(a);
    long long decimalB = hexToDecimal(b);
    long long diff = decimalA - decimalB;
    if (diff < 0) diff = 0; // Ensure no negative results
    return decimalToHex(diff);
}

// Function to add multiple hexadecimal numbers
string addMultipleHex(vector<string>& hexNumbers) {
    long long sum = 0;
    for (const string& hex : hexNumbers) {
        sum += hexToDecimal(hex);
    }
    return decimalToHex(sum);
}

// Function to subtract multiple hexadecimal numbers
string subtractMultipleHex(vector<string>& hexNumbers) {
    if (hexNumbers.empty()) return "0";
    long long diff = hexToDecimal(hexNumbers[0]);
    for (size_t i = 1; i < hexNumbers.size(); i++) {
        diff -= hexToDecimal(hexNumbers[i]);
    }
    return decimalToHex(diff);
}