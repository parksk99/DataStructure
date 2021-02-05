test.exe : test.o cppArray.o
	g++ -o test.exe test.o cppArray.o

test.o : test.cpp
	g++ -c -o test.o test.cpp

cppArray.o : cppArray.cpp cppArray.h
	g++ -c -o cppArray.o cppArray.cpp

clean:
	rm -rf *.o
