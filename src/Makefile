ROMAN_LIBRARY_OBJECTS=roman.o
APP_OBJECTS=roman_app.o main.o

CFLAGS = -g

.PHONY: all clean

all: roman_calc

libroman_numerals.a: roman_numerals.o
	ar r $@ $^

clean:
	rm -f roman_calc
	rm -f *.a
	rm -f *.o

roman_calc: main.o roman_numerals.o libroman_numerals.a
	$(CC) $(CFLAGS) -o $@ $^ -L. -lroman_numerals
	./roman_calc XLIV + VII
	./roman_calc aa + VII

roman_numerals.c: roman_numerals.h
