#include "bitWiseOperations.hpp"
#include "binaryConversion.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <bitset>

using namespace std;

void handleBitWiseOperations() {
	string formatChoice;
	string inputA, inputB;
	uint8_t a = 0, b = 0;

	cout << "\nChoose input format (bin/hex): ";
	cin >> formatChoice;

	// Converts to lowercase and accepts a slew of inputs
	// binary/bin/b or hex/hexadecimal/h/hd
	transform(formatChoice.begin(), formatChoice.end(), formatChoice.begin(), ::tolower);

	cout << "Enter first number: ";
	cin >> inputA;
	// add a validator
	cout << "Enter second number: ";
	cin >> inputB;
	// add a validator

	// Match input type
	if (formatChoice == "bin" || formatChoice == "binary" || formatChoice == "b") {
		a = binaryToUInt8(inputA);
		b = binaryToUInt8(inputB);
	} else if (formatChoice == "h" || formatChoice == "hd" || formatChoice == "hex" || formatChoice == "hexadecimal") {
		a = hexToUInt8(inputA);
		b = hexToUInt8(inputB);
	} else {
		cout << "\nInvalid format choice\n";
		return;
	}

	// Perform bitwise operations
	uint8_t andResult = a & b;
	uint8_t orResult = a | b;
	uint8_t xorResult = a ^ b;
	uint8_t complementA = ~a;
	uint8_t complementB = ~b;

	//
	cout << "\n--- Bit-Wise Results ---" << endl;
    cout << "A         : " << bitset<8>(a) << " (" << (int)a << ")\n";
    cout << "B         : " << bitset<8>(b) << " (" << (int)b << ")\n";

    cout << "A & B     : " << bitset<8>(andResult)
		 << " (decimal: " << (int)andResult
		 << ", binary: " << decimalToBinary(andResult) << ")\n";

    cout << "A | B     : " << bitset<8>(orResult)
		 << " (decimal: " << (int)orResult
		 << ", binary: " << decimalToBinary(orResult) << ")\n";

	cout << "A ^ B     : " << bitset<8>(xorResult)
		 << " (decimal: " << (int)xorResult
		 << ", binary: " << decimalToBinary(xorResult) << ")\n";

	cout << "~A        : " << bitset<8>(complementA)
		 << " (decimal: " << (int)complementA
		 << ", binary: " << decimalToBinary(complementA) << ")\n";

    cout << "~B        : " << bitset<8>(complementB)
		 << " (decimal: " << (int)complementB
		 << ", binary: " << decimalToBinary(complementB) << ")\n";

	cout << "Is A odd: " << isOdd(a) << "\n";
    cout << "Is B odd: " << isOdd(b) << "\n";
}

string isOdd(uint8_t num) {
	return (num & 1) ? "true" : "false";
}

uint8_t binaryToUInt8(const string& binaryInput) {
	return static_cast<uint8_t>(bitset<8>(binaryInput).to_ulong());
}

uint8_t hexToUInt8(const string& hexInput) {
	uint16_t hexValue;
	stringstream ss;
	ss << hexInput << hexInput;
	ss >> hexValue;
	return static_cast<uint8_t>(hexValue);
}


