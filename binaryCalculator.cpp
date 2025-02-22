#include "binaryCalculator.h"
#include <algorithm>

using namespace std;

// Function to add two binary strings
string addBinary(string a, string b) {
    string result = "";
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        result += (sum % 2) + '0';
        carry = sum / 2;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

// Function to subtract two binary strings
string subtractBinary(string a, string b) {
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
    
    while (result.size() > 1 && result.back() == '0')
        result.pop_back();
    
    reverse(result.begin(), result.end());
    return result;
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