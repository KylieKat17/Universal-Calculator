#include "hexCalculator.hpp"
#include "hexConversion.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// Function prototypes
void displayHexMenu();

// Function to handle hexadecimal calculations
void handleHexCalculations() {
    char operation;

    displayHexMenu();
    cin >> operation;
    operation = tolower(operation);

    int n;
    cout << "\nEnter the number of hexadecimal numbers: ";
    cin >> n;

    vector<string> hexNumbers(n);
    cout << "\nEnter the hexadecimal numbers: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> hexNumbers[i];
    }

    string result = (operation == 'a') ? addMultipleHex(hexNumbers) : subtractMultipleHex(hexNumbers);
    cout << "\nResult: " << result << endl;
}

// Function to display hexadecimal operations menu
void displayHexMenu() {
    cout << "\n***** Hexadecimal Calculations *****";
    cout << "\nSelect an operation:";
    cout << "\n  [A]: Add hexadecimal numbers";
    cout << "\n  [S]: Subtract hexadecimal numbers";
    cout << "\nEnter your choice: ";
}

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
