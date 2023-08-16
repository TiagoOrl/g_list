CC=gcc


run: main.o stack.o
	$(CC) -o run main.o stack.o && rm *.o && clear && ./run

main.o: main.c
	$(CC) -c main.c

stack.o: src/stack.c
	$(CC) -c src/stack.c

rm:
	rm *.o run
