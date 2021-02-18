test.exe : test.o sparseMatrix.o
	g++ -o test.exe test.o sparseMatrix.o -g

test.o : test.cpp
	g++ -c -o test.o test.cpp -g

sparseMatrix.o : sparseMatrix.cpp sparseMatrix.h
	g++ -c -o sparseMatrix.o sparseMatrix.cpp -g

clean:
	rm -rf *.o
