test.exe: test.o polinomial.o 
	g++ -o test.exe test.o polinomial.o

test.o : test.cpp header.h
	g++ -c -o test.o test.cpp -g

polinomial.o : polinomial.cpp polinomial.h header.h
	g++ -c -o polinomial.o polinomial.cpp -g

clean :
	rm -rf *.o
