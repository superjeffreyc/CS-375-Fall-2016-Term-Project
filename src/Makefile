OBJS = BruteForce.o main.o KMPSearch.o RabinKarp.o
CC = g++
CFLAGS = -c -std=c++11
LFLAGS = -std=c++11
EXE = SearchComparisons

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

BruteForce.o: BruteForce.h StringSearch.h BruteForce.cpp
	$(CC) $(CFLAGS) BruteForce.cpp -o BruteForce.o

KMPSearch.o: KMPSearch.h StringSearch.h KMPSearch.cpp
	$(CC) $(CFLAGS) KMPSearch.cpp -o KMPSearch.o

RabinKarp.o: RabinKarp.h StringSearch.h RabinKarp.cpp
	$(CC) $(CFLAGS) RabinKarp.cpp -o RabinKarp.o

main.o: BruteForce.h KMPSearch.h RabinKarp.h main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

runMultiple: all
	./SearchComparisons ../test/t3Text.txt ../test/t3Pattern.txt ../test/t3Output.html multiple

run: all
	./SearchComparisons ../test/t3Text.txt ../test/t3Pattern.txt ../test/t3Output.html

clean:
	rm *.o SearchComparisons
	rm ../test/*.html
