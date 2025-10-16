#ifndef HEX_CONVERSION_HPP
#define HEX_CONVERSION_HPP

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

void displayHexConversionMenu();
void handleHexConversions();
long long hexToDecimal(const std::string& hexStr);
std::string decimalToHex(long long decimalValue);

#endif // HEX_CONVERSION_HPP

