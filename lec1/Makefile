CC = g++
test.exe : test.o sort.o binarySearch.o arrayUtil.o permutation.o combination.o ackermann.o
	$(CC) -o test.exe test.o sort.o binarySearch.o arrayUtil.o permutation.o combination.o ackermann.o


test.o : test.cpp
	$(CC) -c -o test.o test.cpp
sort.o : sort.cpp sort.h
	$(CC) -c -o sort.o sort.cpp

binarySearch.o : binarySearch.cpp binarySearch.h
	$(CC) -c -o binarySearch.o binarySearch.cpp

arrayUtil.o : arrayUtil.cpp arrayUtil.h
	$(CC) -c -o arrayUtil.o arrayUtil.cpp
permutation.o : permutation.cpp permutation.h arrayUtil.h
	$(CC) -c -o permutation.o permutation.cpp
combination.o : combination.cpp combination.h
	$(CC) -c -o combination.o combination.cpp
ackermann.o : ackermann.cpp ackermann.h
	$(CC) -c -o ackermann.o ackermann.cpp
clean :
	rm -rf *.o test.exe
