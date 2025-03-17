#ifndef HEX_CONVERSION_H
#define HEX_CONVERSION_H

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

void displayHexConversionMenu();
void handleHexConversions();
long long hexToDecimal(const std::string& hexStr);
std::string decimalToHex(long long decimalValue);

#endif
