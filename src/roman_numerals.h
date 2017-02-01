#ifndef _ROMAN_NUMERAL__
#define _ROMAN_NUMERAL__

// Value to Roman Numeral
// val    - Input value
// ret    - Return buffer
// retLen - Size of return buffer
short  value2numeral(short val, char* ret, int retLen);

// Roman Numeral to Value
// str  - Roman Numeral
// Return negative value when illegal character is detected
short  numeral2value(const char* str);

// Add or subtract two roman numerals.
// lhs    - Roman numeral Left Hand Side
// rhs    - Roman numeral Right Hand Side
// Return string containing result
char* calculate(char* lhs, char addSub, char* rhs);

#endif

