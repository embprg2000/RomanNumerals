CFLAGS = `pkg-config --cflags check`
LIBS = `pkg-config --libs check` -L../src -lroman_numerals
VPATH=../src

test_calc: test_calc.o ../src/libroman_numerals.a
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f test_calc
