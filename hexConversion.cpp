#include "hexConversion.h"

using namespace std;

// Function to handle hex conversion menu
void handleHexConversions() {
    char conversion;
    
    displayHexConversionMenu();
    cin >> conversion;
    conversion = tolower(conversion);
    
    if (conversion == 'd') {
        int decimal;
        cout << "\nEnter a decimal number: ";
        cin >> decimal;
        cout << "\nHexadecimal equivalent: " << decimalToHex(decimal) << endl;
    } else if (conversion == 'h') {
        string hex;
        cout << "\nEnter a hexadecimal number: ";
        cin >> hex;
        cout << "\nDecimal equivalent: " << hexToDecimal(hex) << endl;
    } else {
        cout << "\nInvalid conversion choice." << endl;
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