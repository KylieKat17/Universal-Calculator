#include "binaryConversion.hpp"
#include "util.hpp"
#include <iostream>

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
        printInvalidInputMessage();
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