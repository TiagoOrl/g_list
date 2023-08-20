CC=gcc
DEBUG=-g


run: main.o list.o
	$(CC) -o run main.o list.o $(DEBUG) && rm *.o && clear && ./run

main.o: main.c
	$(CC) -c main.c $(DEBUG)

list.o: src/list.c
	$(CC) -c src/list.c $(DEBUG)

cl:
	rm *.o run
