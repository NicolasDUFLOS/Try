all : try_mul

try_mul : try.o try_mul.c
	gcc -o try_mul try.o try_mul.c -Wall -O -m32

try.o : try.c
	gcc -c try.c
