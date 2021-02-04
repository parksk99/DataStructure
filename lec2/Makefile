test.exe : test.o rectangle.o currency.o
	g++ -o test.exe test.o rectangle.o currency.o

test.o : test.cpp header.h
	g++ -c -o test.o test.cpp

rectangle.o : rectangle.cpp rectangle.h
	g++ -c -o rectangle.o rectangle.cpp

currency.o : currency.cpp currency.h
	g++ -c -o currency.o currency.cpp

clean:
	rm -rf *.o
