#ifndef HEX_CALCULATOR_H
#define HEX_CALCULATOR_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

std::string addHex(std::string a, std::string b);
std::string subtractHex(std::string a, std::string b);
std::string addMultipleHex(std::vector<std::string>& hexNumbers);
std::string subtractMultipleHex(std::vector<std::string>& hexNumbers);

#endif
