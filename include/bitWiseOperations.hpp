#ifndef BITWISEOPERATIONS_HPP
#define BITWISEOPERATIONS_HPP

#include <string>
#include <cstdint>
#include <bitset>
#include <sstream>
#include <iomanip>
#include "binaryConversion.h"

using namespace std;

void handleBitWiseOperations();
string isOdd(uint8_t);
uint8_t binaryToUInt8(const string&);
uint8_t hexToUInt8(const string&);

#endif //BITWISEOPERATIONS_HPP

