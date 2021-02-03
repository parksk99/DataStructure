#include"header.h"
void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap(char *a, char* b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
void copy(int *a, int *b, int n){
	for(int i=n-1; i>=0; i--) {
		b[i] = a[i];
	}
	return;
}
void PrintArray(int *array, int n){
	for(int i=0; i<n; i++) std::cout<<array[i]<<" ";
	std::cout<<std::endl;
	return;
}
