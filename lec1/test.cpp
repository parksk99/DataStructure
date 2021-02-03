#include"header.h"
#include"ackermann.h"
#include"combination.h"
#include"permutation.h"
#include"arrayUtil.h"
#include"sort.h"
#include"binarySearch.h"

int main(){
	int array[10] = {2,3,4,5,1,8,0,19,10,11};
	PrintArray(array, 10);
	std::cout<<std::endl;
//	SelectionSort(array, 10);
//	BubbleSort(array, 10);
	InsertionSort(array, 10);

	PrintArray(array, 10);
	std::cout<<BinarySearch(array, 100, 10)<<std::endl;
	std::cout<<RecursiveBinarySearch(array, 8, 0, 9)<<std::endl;

	char str[4] = "abc";
	Permutation(str, 0, 3);
	std::cout<<"6C3 : "<<Combination(30,5)<<std::endl;
	std::cout<<"Ackermann(5,2) : "<<Ackermann(2,1)<<std::endl;
	return 0;
}
