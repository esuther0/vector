CFLAGS=-std=c11 -Wpedantic -Werror -Wall

test: vector.c vector_test.c
	gcc $(CFLAGS) vector.c vector_test.c -o test
	./test

debug:
	gcc $(CFLAGS) vector.c vector_test.c -o test -g

clean:
	rm -f test