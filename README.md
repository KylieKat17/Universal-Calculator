# Universal-Calculator
C++ calculator for binary calculations, hexadecimal calculations, and binary/hex/decimal conversions

Originally made for checking manual calculations in CPSC 2310 after I couldn't find a program or website that allowed me to add/subtract multiple binary or hexadecimal numbers at one time. Started small, but as I was taking a quiz, I expanded it. For now, it's rather basic (other than that it can add/subtract multiple numbers at once). I basically want this to be my one stop shop for checking manual calculations required for Chapter 2 of CPSC 2310's coursework, so I'll be updating as the course progresses. As of 3/4/2025, while literally in the middle of taking a Lab Quiz, I've decided to expand this "calculator" to handle everything in the to be added section, in no particular order.. I will be including a copy of the notes from this class that were used as reference. Eventually, there will be a working list of all the capabilities in the present version on here. This has been a great learning excercise for me. This is not the property of Clemson University, and I'm making this open-source on the condition that I get attribution. I will also include a list of any sites or reopositories I used as reference while writing this (I had to do the checking somehow, after all!). I will try *my best* to make sure the padding is displayed on any binary output, but will have to do so as I catch that it isn't.

To Be Added (FOR SURE)
- Endian ordering functionality
- Determining hexadecimal based on 2^n
- Bitwise Calculatator
  - Bit-wise operations: NOT, AND, OR, XOR (~, &, |, ^)
    - Support for Hex operations (so takes in Hex, converts to binary, conducts binary operation, and converts back to hex)  
  - Bit-wise binary shifting (left, right (Logical), right (Arithmatic))
- Logical Operations (outputs 0x00 (TRUE) or 0x01 (FALSE)
- Signed/Unsigned Data ranges for word sizes
- Values for Signed/Unsined Calculator(s)
  - Data ranges for word sizes given an integer (W=?)
  - Values for signed and unsigned binary strings
- Complement calculator (positive to negative binary and vice versa)
  - -25 <-> 25

To Be Added (POSSIBLY)
- 


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
