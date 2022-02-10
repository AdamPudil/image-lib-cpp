output: main.o img.o
	g++ main.o img.o -o main

main.o: main.cpp
	g++ -Wall -pedantic -c main.cpp

img.o: img.cpp
	g++ -Wall -pedantic -c img.cpp

clean:
	rm *.o main
