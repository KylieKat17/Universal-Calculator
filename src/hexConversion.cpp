#include "hexConversion.hpp"
#include "util.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function to handle hex conversion menu
void handleHexConversions() {
    char conversion;
    
    displayHexConversionMenu();
    cin >> conversion;
    conversion = tolower(conversion);
    
    if (conversion == 'd') {
        string input;
        cout << "\nEnter a decimal number: ";
        cin >> input;

        input = trimWhitespace(input);
        stringstream ss(input);
        long long decimal;
        ss >> decimal;

        cout << "\nHexadecimal equivalent: " << decimalToHex(decimal) << endl;
    } else if (conversion == 'h') {
        string hex;
        cout << "\nEnter a hexadecimal number: ";

        hex = trimWhitespace(toLowercase(hex));
        if (!isValidHex(hex)) {
            printInvalidInputMessage();
            return;
        }

        cin >> hex;
        cout << "\nDecimal equivalent: " << hexToDecimal(hex) << endl;
    } else {
        printInvalidInputMessage();
    }
}

// Function to display conversion options
void displayHexConversionMenu() {
    cout << "\n***** Hexadecimal Conversions *****";
    cout << "\nSelect a conversion type:";
    cout << "\n  [D]: Convert decimal to hexadecimal";
    cout << "\n  [H]: Convert hexadecimal to decimal";
    cout << "\nEnter your choice: ";
}