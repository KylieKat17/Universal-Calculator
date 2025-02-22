#include "hexConversion.h"

using namespace std;

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
