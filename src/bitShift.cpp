#include "bitShift.hpp"

using namespace std;

// Function to perform bitwise shift operations
void handleBitShifting() {
	string input;
	int shiftAmount;
	char choice;

	cout << "\n**** Bit Shift Operations ****" << endl;
	cout << "Enter a binary number: ";
	cin >> input;

	cout << "\nEnter the number of positions to  shift by: ";
	cin >> shiftAmount;

	do {
		displayBitShiftMenu();
		cin >> choice;
		choice = tolower(choice);

		switch (choice) {
		case 'l':
			cout << "\nResult: " << logicalLeftShift(input, shiftAmount)
				 << endl;
			break;
		case 'r':
			cout << "\nResult: " << logicalRightShift(input, shiftAmount)
				 << endl;
			break;
		case 'a':
			cout << "\nResult: " << arithmeticRightShift(input, shiftAmount)
				 << endl;
			break;
		case 'p':
			performAllShifts(input, shiftAmount);
			break;
		case 'q':
			cout << "\nExiting bit shift calculator..." << endl;
			break;
		default:
			cout << "Invalid choice. Please select L, R, A, P, or Q." << endl;
		}
	} while (choice != 'q');
}

// Display menu for bit shifting options
void displayBitShiftMenu() {
	cout << "\nChoose Shift Type:" << endl;
	cout << "  [L]: Logical Left Shift" << endl;
	cout << "  [R]: Logical Right Shift" << endl;
	cout << "  [A]: Arithmetic Right Shift" << endl;
	cout << "  [P]: Perform All Shifts" << endl;
	cout << "  [Q]: Quit" << endl;
	cout << "Enter your choice: ";
}

// Logical Left Shift
string logicalLeftShift(const string &binary, int shiftAmount) {
	string result = binary.substr(shiftAmount);
	result.append(shiftAmount, '0');
	return result;
}

// Logical Right Shift
string logicalRightShift(const string &binary, int shiftAmount) {
	string result = binary;
	result.insert(0, shiftAmount, '0');
	return result.substr(0, binary.length());
}

// Arithmetic Right Shift
string arithmeticRightShift(const string &binary, int shiftAmount) {
	char signBit = binary[0];
	string result = binary;
	result.insert(0, shiftAmount, signBit);
	return result.substr(0, binary.length());
}

// Perform All Shifts
void performAllShifts(const string &binary, int shiftAmount) {
	cout << "\n--- Results of all shifts ---" << endl;
	cout << "Logical Left Shift:      " << logicalLeftShift(binary, shiftAmount)
		 << endl;
	cout << "Logical Right Shift:     "
		 << logicalRightShift(binary, shiftAmount) << endl;
	cout << "Arithmetic Right Shift:  "
		 << arithmeticRightShift(binary, shiftAmount) << endl;
}
