#ifndef _ROMAN_NUMERAL__
#define _ROMAN_NUMERAL__

short value2numeral(short val, char* ret, int retLen);
short numeral2value(const char* str);
short calculate(char* lhs, char addSub, char* rhs, char* ret, int retLen);

#endif
