#ifndef SORT_H
#define SORT_H
#include"arrayUtil.h"
template<class T>
void SelectionSort(T* array, const int size){
	int minIndex;
	for(int i=0; i<size; i++){
		minIndex = i;
		for(int j=i; j<size; j++){
			if(array[minIndex] > array[j]) minIndex = j;
		}
		swap(array[i], array[minIndex]);
	}
}
#endif
