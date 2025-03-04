# Universal-Calculator
C++ calculator for binary calculations, hexadecimal calculations, and binary/hex/decimal conversions

Made for checking manual calculations in CPSC 2310 after I couldn't find a program or website that allowed me to add/subtract multiple binary or hexadecimal numbers at one time. Started small, but as I was taking a quiz, I expanded it. For now, it's rather basic (other than that it can add/subtract multiple numbers at once). I basically want this to be my one stop shop for checking manual calculations required for Chapter 2 of CPSC 2310's coursework, so I'll be updating as the course progresses.

To Be Added
- Endian ordering functionality
- Determining hexadecimal based on 2^n
- Bitwise Calculatator
- Complement calculator (positive to negative binary and vice versa)
  - -25 <-> 25

---
### Version Release

**V2.0 - 2/25/2025**

*Menu/Driver*
- Simplified driver to only display the initial menu and then call functions from other files to direct to further calculations/conversion menus and logic

*Binary Calculations*
- Menu and input prompts have been moved to here
- Updated binary subtraction/addition to allow for inputs of different lengths
- Updated binary subtraction/addition to handle padding on the outputs (accounts for inputs of different lengths)
  - Probably should test on 00000000 +/- 00000000 or outputs with multiple leading 0s

*Hexadecimal Calculations*
- Menu and input prompts have been moved here
- WIll update for multiple input lengths in V2.1

*Conversions*
- Fixed the padding issue for hex to binary conversion

**V1.0 - 2/22/2025**

*Menu/Driver*
- Rudimentary menu and logic directory. Needs to be updated for style and readability with indents and spacer lines

*Binary calculations*
- Multi-number binary addition
- Multi-number binary subtraction

*Hexadecimal*
- Hexadecimal addition
- Hexadecimal subtraction
  - The implementation for multi-number calculations exists, but has not been tested

*Conversions*
- Binary <-> decimal conversion
- Binary <-> hexadecimal conversion
- Hexadecimal <-> decimal conversion
  - The implementation exists in hexConversion.cpp, but hasn't been implemented on it's own under the conversions. Has been successfully called for basic hexadecimal addition/subtraction
 
*Makefile*
- Basic makefile that has functions for make, make run, and make clean. Needs to be cleaned up and shortened at a later date.

---

**Machine Specs**
Compiled and tested on a machine with the following specs:
LSB Version:    core-11.1.0ubuntu2-noarch:security-11.1.0ubuntu2-noarch
Distributor ID: Ubuntu
Description:    Ubuntu 20.04.6 LTS
Release:        20.04
Codename:       focal

---
