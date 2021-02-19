test.exe : test.o string.o
	g++ -o test.exe test.o string.o -g

test.o : test.cpp
	g++ -c -o test.o test.cpp -g

string.o : string.cpp string.h
	g++ -c -o string.o string.cpp -g

clean :
	rm -rf *.o
