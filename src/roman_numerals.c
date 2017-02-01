#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "roman_numerals.h"

static char cMap[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
static short vMap[] = { 1, 5, 10, 50, 100, 500, 1000 };
static short cMapLen = 7;

// Return index in character table. When the character is not found return -1.
static short char2idx(char c) {
    int i;

    for (i = 0; i < cMapLen; ++i) {
        if (c == cMap[i])
            break;
    }
    return (i == cMapLen) ? -1 : i;
}

short numeral2value(const char* str) {
    short i = 0;
    short idx1;
    short idx2;
    short val = 0;

    while (i < strlen(str) && val >= 0) {
        idx1 = char2idx(str[i]);

        if (idx1 >= 0) {
            if (i < strlen(str) - 1) {
                idx2 = char2idx(str[i + 1]);
                if (idx1 < idx2) {
                    if (idx2 > 0) {
                        // If the value of the next character if higher
                        // then the value of the current character.
                        val += vMap[idx2] - vMap[idx1];
                        i += 2;
                    } else {
                        // Invalid character.
                        val = -i - 1;
                    }
                } else {
                    val += vMap[idx1];
                    ++i;
                }
            } else {
                val += vMap[idx1];
                ++i;
            }
        } else {
            // Invalid character.
            val = -i - 1;
        }
    }
    return val;
}

short value2numeral(short val, char* ret, int retLen) {
    int i = 0;
    char* ptr;
    int len;
    char* mil = "MMMMMMMMMMMMMMM";
    char* map1[]   = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X" };
    char* map10[]  = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C" };
    char* map100[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M" };

    // Limit input range. 
    if (val < 0 || val > 10000)
    {
        strcpy(ret, "Error");
        return -1;
    }

    // Instead of tables I could also use a little algorithm. However in this case
    // I think in this case a table make the code easier to read.
    memset((void*) ret, 0, retLen);
    while (val > 0) {
        short n = val % 10;

        switch (i) {
        case 0:
            ptr = map1[n];
            break;
        case 1:
            ptr = map10[n];
            break;
        case 2:
            ptr = map100[n];
            break;
        case 3:
            ptr = &mil[strlen(mil) - n];
            break;
        }

        len = strlen(ptr);
        if (retLen - len - 1 < 0) {
            val = -1;
            strcpy(ret, "Err");
        } else {
            // Since the algorithm starts with the digits on the right we
            // we fill the buffer from the end.
            memcpy(&ret[retLen - len - 1], ptr, len);
            retLen -= len;

            val /= 10;
            ++i;
        }
    }

    if (retLen - 1 < 0) {
        strcpy(ret, "Error");
    } else {
        ptr = &ret[retLen - 1];
        memmove(ret, ptr, strlen(ptr) + 1);
    }
    return 0;
}

char* calculate(char* lhs, char addSub, char* rhs) {
    short err = 0;
    short lhsVal;
    short rhsVal;
    static char  buff[50];

    lhsVal = numeral2value(lhs);
    rhsVal = numeral2value(rhs);

    if (lhsVal > 0 && rhsVal > 0)
    {
        // Validity check of addSub character was done in main.
        if (addSub == '+')
            err = value2numeral(lhsVal + rhsVal, buff, 50);
        else
            err = value2numeral(lhsVal - rhsVal, buff, 50);
    }
    else
        err = -1;
        
    if (err < 0)
        strcpy(buff, "Error");
    return buff;
}
