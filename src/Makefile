OBJS = BruteForce.o main.o KMPSearch.o RabinKarp.o #add rest of objs
CC = g++
CFLAGS = -c -std=c++11
LFLAGS = -std=c++11
EXE = SearchComparisons

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

BruteForce.o: BruteForce.h BruteForce.cpp
	$(CC) $(CFLAGS) BruteForce.cpp -o BruteForce.o
	
KMPSearch.o: KMPSearch.h KMPSearch.cpp
	$(CC) $(CFLAGS) KMPSearch.cpp -o KMPSearch.o
	
RabinKarp.o: RabinKarp.h RabinKarp.cpp
	$(CC) $(CFLAGS) RabinKarp.cpp -o RabinKarp.o
	
main.o: BruteForce.h KMPSearch.h RabinKarp.h main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

run: all
	./SearchComparisons
	
clean:
	rm *.o SearchComparisons
