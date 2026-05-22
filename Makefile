CC=gcc
DEBUG=-g


all: ./build/main.o ./build/list.o
	$(CC) -o run ./build/main.o ./build/list.o $(DEBUG)

./build/main.o: ./src/main.c
	$(CC) -c ./src/main.c -o ./build/main.o  $(DEBUG)

./build/list.o: ./src/list/list.c
	$(CC) -c ./src/list/list.c -o ./build/list.o $(DEBUG)

cl:
	rm ./build/*.o run
