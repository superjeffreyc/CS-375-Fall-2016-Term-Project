OBJS = BruteForce.o main.o #add rest of objs
CC = g++
CFLAGS = -c -std=c++11
LFLAGS = -std=c++11
EXE = SearchComparisons

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

BruteForce.o: BruteForce.h BruteForce.cpp
	$(CC) $(CFLAGS) BruteForce.cpp -o BruteForce.o

main.o: BruteForce.h main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

clean:
	rm *.o SearchComparisons
