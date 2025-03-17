#include "binaryCalculator.h"
#include <iostream>

using namespace std;

// Function prototypes
void displayBinaryMenu();
string padBinary(string binary, size_t length);


// Function prototypes
void displayBinaryMenu();
string padBinary(string binary, size_t length);
string trimLeadingZeros(string binary);

// Function to handle binary calculations
void handleBinaryCalculations() {
    char operation;
    
    displayBinaryMenu();
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
    
    // Determine the required bit length based on the longest input
    size_t maxLength = 0;
    for (const string& binary : binaries) {
        if (binary.length() > maxLength) {
            maxLength = binary.length();
        }
    }
    
    // Ensure maxLength accounts for potential carry
    maxLength += 1;

    // Pad all inputs to the same length
    for (string &binary : binaries) {
        binary = padBinary(binary, maxLength);
    }
    
    string result = (operation == 'a') ? addMultipleBinaries(binaries) : subtractMultipleBinaries(binaries);

    // Ensure the result is correctly padded to match the longest input length
    // and remove leading zeros while keeping at least one bit for addition
    if (operation == 'a') {
        result = trimLeadingZeros(result);
    } else {
        result = padBinary(result, maxLength);
    }

    cout << "\nResult: " << result << endl;
}

// Function to display binary operations menu
void displayBinaryMenu() {
    cout << "\n***** Binary Calculations *****";
    cout << "\nSelect an operation:";
    cout << "\n  [A]: Add binary numbers";
    cout << "\n  [S]: Subtract binary numbers";
    cout << "\nEnter your choice: ";
}

// Function to pad binary numbers to maintain leading zeros
string padBinary(string binary, size_t length) {
    while (binary.length() < length) {
        binary = '0' + binary;
    }
    return binary;
}

// Function to trim excessive leading zeros while ensuring at least one leading zero
string trimLeadingZeros(string binary) {
    size_t firstOne = binary.find_first_not_of('0');
    if (firstOne == string::npos) {
        return "0"; // If all zeros, return a single zero
    }
    return "0" + binary.substr(firstOne);
}

// Function to add two binary strings
string addBinary(string a, string b) {
    // Ensure both numbers are the same length before adding
    size_t maxLength = max(a.length(), b.length()) + 1; // Account for carry
    a = padBinary(a, maxLength);
    b = padBinary(b, maxLength);
    
    string result = "";
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        result += (sum % 2) + '0';
        carry = sum / 2;
    }
    
    if (carry) result += '1'; // Account for final carry
    
    reverse(result.begin(), result.end());
    return result;
}

// Function to subtract two binary strings
string subtractBinary(string a, string b) {
    size_t maxLength = max(a.length(), b.length());
    a = padBinary(a, maxLength);
    b = padBinary(b, maxLength);
    
    string result = "";
    int borrow = 0, i = a.size() - 1, j = b.size() - 1;
    
    while (i >= 0 || j >= 0) {
        int diff = (i >= 0 ? a[i--] - '0' : 0) - (j >= 0 ? b[j--] - '0' : 0) - borrow;
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += diff + '0';
    }
    
    reverse(result.begin(), result.end());
    return padBinary(result, maxLength);
}

// Function to add multiple binary numbers
string addMultipleBinaries(vector<string>& binaries) {
    string sum = "0";
    for (const string& binary : binaries) {
        sum = addBinary(sum, binary);
    }
    return sum;
}

// Function to subtract multiple binary numbers
string subtractMultipleBinaries(vector<string>& binaries) {
    if (binaries.empty()) return "0";
    string diff = binaries[0];
    for (size_t i = 1; i < binaries.size(); i++) {
        diff = subtractBinary(diff, binaries[i]);
    }
    return diff;
}