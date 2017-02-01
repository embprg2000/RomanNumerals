#include <stdlib.h>
#include <stdio.h>
#include "roman_numerals.h"

int main(int argc, char **argv)
{
	char *lhs;
	char *rhs;	
	char addSub;
	char buff[50];

	if (argc != 4) {
		fprintf(stderr, "Usage: %s ROMAN_NUMERAL [+-] ROMAN_NUMERAL\n", argv[0]);
		return EXIT_FAILURE;
	}

	lhs = argv[1];
	rhs = argv[3];
	addSub = argv[2][0];

	if (addSub != '-' && addSub != '+') {
		fprintf(stderr, "Error: operator must be + or -\n");
		return EXIT_FAILURE;
	}

	calculate(lhs, addSub, rhs, buff, 50);
	printf("%s\n", buff);

	return EXIT_SUCCESS;
}
