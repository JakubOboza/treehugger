MFLAGS = -c
FLAGS = -Wall --ansi --pedantic
CC = gcc
O_FILES = thread.o configuration.o connection.o

all: final

final: $(O_FILES) main.o
	$(CC) $(FLAGS) $(O_FILES) main.o -o treehugger.run

main.o: main.c
	$(CC) $(FLAGS) $(MFLAGS) main.c

test.o: test.c
	$(CC) $(FLAGS) $(MFLAGS) test.c

thread.o: thread.c
	$(CC) $(FLAGS) $(MFLAGS) -lpthread thread.c

configuration.o: configuration.c
	$(CC) $(FLAGS) $(MFLAGS) configuration.c

connection.o: connection.c
	$(CC) $(FLAGS) $(MFLAGS) -lsocket connection.c

test: test.o $(O_FILES)
	$(CC) $(FLAGS) $(O_FILES) test.c -o test.run

clean:
	rm -rf *.o
