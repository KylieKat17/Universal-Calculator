#include <iostream>
#include "binaryCalculator.h"
#include "binaryConversion.h"
#include "hexCalculator.h"
#include "hexConversion.h"

using namespace std;

// Function prototypes
void displayMainMenu();

// Main driver function
int main() {
    char choice;
    
    while (true) {
        displayMainMenu();
        cin >> choice;
        choice = tolower(choice);
        
        switch (choice) {
            case 'b':
                handleBinaryCalculations();
                break;
            case 'h':
                handleHexCalculations();
                break;
            case 'c':
                handleHexConversions();
                break;
            case 'x':
                handleBinaryConversions();
                break;
            case 'q':
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    }
    return 0;
}

// Function to display the main menu and get user input
void displayMainMenu() {
    cout << "\n********* Universal Calculator *********";
    cout << "\nSelect an operation category:";
    cout << "\n  [B]: Binary calculations (addition/subtraction)";
    cout << "\n  [H]: Hexadecimal calculations (addition/subtraction)";
    cout << "\n  [C]: Hexadecimal conversions (hex <-> decimal)";
    cout << "\n  [X]: Binary conversions (decimal <-> binary, binary <-> hex)";
    cout << "\n  [Q]: Quit program";
    cout << "\nEnter your choice: ";
}