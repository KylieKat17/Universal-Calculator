#include <iostream>
#include "binaryCalculator.h"
#include "binaryConversion.h"
#include "hexCalculator.h"
#include "hexConversion.h"

using namespace std;

// Function prototypes
void runMenuSystem();
char runMenu();

// Main driver function
int main() {
    runMenuSystem();
    return 0;
}

// Function to display the main menu and handle user selection
void runMenuSystem() {
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
            case 'q':
                return;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
}

// Function to display the main menu and get user input
char runMenu() {
    char choice;
    
    cout << "********* Universal Calculator *********" << endl;;
    cout << "Select an operation category:" << endl;;
    cout << "  [1]: Binary Calculations" << endl;
    cout << "  [2]: Hexadecimal Calculations" << endl;
    cout << "  [3]: Conversions" << endl;
    cout << "  [Q]: Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return tolower(choice);
}