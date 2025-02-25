#include "binaryConversion.h"
#include <algorithm>

using namespace std;

// Function prototypes
void displayConversionMenu();

// Function to handle conversions
void handleConversions() {
    char conversion;
    
    displayConversionMenu();
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
void displayConversionMenu() {
    cout << "\n***** Conversion Options *****" << endl;
    cout << "\nSelect a conversion type:" << endl;
    cout << "\t[D]: Convert decimal to binary" << endl;
    cout << "\t[B]: Convert binary to decimal" << endl;
    cout << "\t[H]: Convert binary to hexadecimal" << endl;
    cout << "\t[X]: Convert hexadecimal to binary" << endl;
    cout << "\n\tEnter your choice: ";
}

// Function to convert decimal to binary with at least 8-bit padding
string decimalToBinary(int num) {
    // V2???
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
