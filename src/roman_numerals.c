#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "roman_numerals.h"

short  numeral2value(const char* str)
{
	short val = -1;
	return val;
}

char*  value2numeral(short val)
{
	return "Not jet";
}

char* calculate(char* lhs, char addSub, char* rhs)
{
	short lhsVal;
	short rhsVal;
	
	lhsVal = numeral2value(lhs);
	rhsVal = numeral2value(rhs);
	
	// Validity check of addSub character was done in main.
	if (addSub == '+')	
		return value2numeral(lhsVal + rhsVal);
	else
		return value2numeral(lhsVal - rhsVal);
}
