#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "roman_numerals.h"

static char  cMap[] = {'I','V','X','L','C','D', 'M'};
static short vMap[] = { 1,  5, 10, 50,100,500,1000};

short cMapLen = 7;

// Return index in character table. When the character is not found return -1.
static short char2idx(char c)
{
	int i;

	for (i=0; i<cMapLen; ++i)
	{
		if (c == cMap[i])
			break;
	}
	return (i == cMapLen) ? -1 : i;
}

short  numeral2value(const char* str)
{
	short i = 0;
	short idx1;
	short idx2;
	short val = 0;

	while ( i<strlen(str) )
	{
		idx1 = char2idx( str[i] );

		if (idx1 >= 0) {
			if (i < strlen(str)-1) {
				idx2 = char2idx( str[i+1] );
				if (idx1 < idx2) {
					if (idx2 > 0) {
						val += vMap[idx2] - vMap[idx1];
						i += 2;
					} else {
						// Invalid character.
						val = -i;
					}
				} else {
					val += vMap[idx1];
					++i;
				}
			} else {
				val += vMap[idx1];
				++i;
			}
		} else 	{
			// Invalid character.
			val = -i;
		}
	}
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
