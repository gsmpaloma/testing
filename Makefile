build:
	gcc -Wall -std=c99 ./test*.c -lSDL2  -o out

run:
	./out

clean:
	rm mytest

