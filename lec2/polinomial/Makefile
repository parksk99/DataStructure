test.exe: test.o polinomial.o 
	g++ -g -o test.exe test.o polinomial.o

test.o : test.cpp header.h
	g++ -c -o test.o test.cpp

polinomial.o : polinomial.cpp polinomial.h header.h
	g++ -c -o polinomial.o polinomial.cpp

clean :
	rm -rf *.o
