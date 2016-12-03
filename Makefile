all: driver.o rabinkarp.o
	g++ -std=c++11 driver.o rabinkarp.o -o submission

driver.o: driver.cpp
	g++ -std=c++11 -c driver.cpp -o driver.o

rabinkarp.o: rabinkarp.cpp
	g++ -std=c++11 -c rabinkarp.cpp -o rabinkarp.o

run: all
	./submission pattern.txt text.txt

clean:
	rm *.o submission
