#include "binaryConversion.hpp"
#include <algorithm>

using namespace std;

// Function to handle conversions
void handleBinaryConversions() {
    char conversion;
    
    displayBinaryConversionMenu();
    cin >> conversion;
    conversion = tolower(conversion);
    
    if (conversion == 'd') {
        int decimal;
        cout << "\nEnter a decimal number: ";
        cin >> decimal;
        cout << "\nBinary equivalent: " << decimalToBinary(decimal) << endl;
    } else if (conversion == 'b') {
        string binary;
        cout << "\nEnter a binary number: ";
        cin >> binary;
        cout << "\nDecimal equivalent: " << binaryToDecimal(binary) << endl;
    } else if (conversion == 'h') {
        string binary;
        cout << "\nEnter a binary number: ";
        cin >> binary;
        cout << "\nHexadecimal equivalent: " << binaryToHex(binary) << endl;
    } else if (conversion == 'x') {
        string hex;
        cout << "\nEnter a hexadecimal number: ";
        cin >> hex;
        cout << "\nBinary equivalent: " << hexToBinary(hex) << endl;
    } else {
        cout << "\nInvalid conversion choice." << endl;
    }
}

// Function to display conversion options
void displayBinaryConversionMenu() {
    cout << "\n***** Binary Conversions *****";
    cout << "\nSelect a conversion type:";
    cout << "\n  [D]: Convert decimal to binary";
    cout << "\n  [B]: Convert binary to decimal";
    cout << "\n  [H]: Convert binary to hexadecimal";
    cout << "\n  [X]: Convert hexadecimal to binary";
    cout << "\nEnter your choice: ";
}

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
    //ss << hex << setw((binary.size() / 4)) << setfill('0') << decimal;
    // V1
    ss << hex << decimal;
    return ss.str();
}

// Function to convert hexadecimal to binary with at least 8-bit padding
string hexToBinary(string hex) {
    int decimal;
    stringstream ss;
    ss << std::hex << hex;  // Convert hex string to decimal
    ss >> decimal;
    return decimalToBinary(decimal);  // Convert decimal to binary
}
