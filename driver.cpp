#include <iostream>
#include <vector>
#include "binaryCalculator.h"
#include "binaryConversion.h"
#include "hexCalculator.h"

using namespace std;

// Function to display the main menu
char runMenu() {
    char choice;
    cout << "********* Universal Calculator *********" << endl;
    cout << "Select an operation category:" << endl;
    cout << "1: Binary Calculations" << endl;
    cout << "2: Hexadecimal Calculations" << endl;
    cout << "3: Conversions" << endl;
    cout << "Q: Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return tolower(choice);
}

// Function to handle binary operations
void handleBinaryCalculations() {
    char operation;
    cout << "Select Binary Operation:" << endl;
    cout << "a: Add binary numbers" << endl;
    cout << "s: Subtract binary numbers" << endl;
    cin >> operation;
    operation = tolower(operation);
    
    int n;
    cout << "Enter the number of binary numbers: ";
    cin >> n;
    
    vector<string> binaries(n);
    cout << "Enter the binary numbers: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> binaries[i];
    }
    
    string result = (operation == 'a') ? addMultipleBinaries(binaries) : subtractMultipleBinaries(binaries);
    cout << "Result: " << result << endl;
}

// Function to handle hexadecimal operations
void handleHexCalculations() {
    char operation;
    cout << "Select Hexadecimal Operation:" << endl;
    cout << "A: Add hexadecimal numbers" << endl;
    cout << "S: Subtract hexadecimal numbers" << endl;
    cin >> operation;
    operation = tolower(operation);

    
    int n;
    cout << "Enter the number of hexadecimal numbers: ";
    cin >> n;
    
    vector<string> hexNumbers(n);
    cout << "Enter the hexadecimal numbers: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> hexNumbers[i];
    }
    
    string result = (operation == 'a') ? addMultipleHex(hexNumbers) : subtractMultipleHex(hexNumbers);
    cout << "Result: " << result << endl;
}

// Function to handle conversions
void handleConversions() {
    char conversion;
    cout << "Select Conversion Type:" << endl;
    cout << "d: Convert decimal to binary" << endl;
    cout << "b: Convert binary to decimal" << endl;
    cout << "h: Convert binary to hexadecimal" << endl;
    cout << "x: Convert hexadecimal to binary" << endl;
    cin >> conversion;
    conversion = tolower(conversion);

    
    if (conversion == 'd') {
        int decimal;
        cout << "Enter a decimal number: ";
        cin >> decimal;
        cout << "Binary equivalent: " << decimalToBinary(decimal) << endl;
    } else if (conversion == 'b') {
        string binary;
        cout << "Enter a binary number: ";
        cin >> binary;
        cout << "Decimal equivalent: " << binaryToDecimal(binary) << endl;
    } else if (conversion == 'h') {
        string binary;
        cout << "Enter a binary number: ";
        cin >> binary;
        cout << "Hexadecimal equivalent: " << binaryToHex(binary) << endl;
    } else if (conversion == 'x') {
        string hex;
        cout << "Enter a hexadecimal number: ";
        cin >> hex;
        cout << "Binary equivalent: " << hexToBinary(hex) << endl;
    } else {
        cout << "Invalid conversion choice." << endl;
    }
}

// Main driver function
int main() {
    char menuChoice;
    while (true) {
        menuChoice = runMenu();
        switch (menuChoice) {
            case '1':
                handleBinaryCalculations();
                break;
            case '2':
                handleHexCalculations();
                break;
            case '3':
                handleConversions();
                break;
            case 'Q':
            case 'q':
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
