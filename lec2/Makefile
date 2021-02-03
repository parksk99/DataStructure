test.exe : test.o rectangle.o
	g++ -o test.exe test.o rectangle.o

test.o : test.cpp header.h
	g++ -c -o test.o test.cpp

rectangle.o : rectangle.cpp rectangle.h
	g++ -c -o rectangle.o rectangle.cpp

clean:
	rm -rf *.o
