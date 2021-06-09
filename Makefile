CC=g++

CFLAGS=-Wall -Wextra -std=c++11 -g
CFLAGS += -Iinc




all: main



main: main.cpp obj/utils.o
	$(CC) $(CFLAGS) $^ -o $@

obj/utils.o: src/utils.cpp
	mkdir obj/
	$(CC) $(CFLAGS)  $^ -c -o $@

clean:
	rm -rf *.o src/*.o
	rm -rf obj/*.o
	rm -rf obj/