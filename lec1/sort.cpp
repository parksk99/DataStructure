#include"arrayUtil.h"
void SelectionSort(int *array, int n){
	int tmp = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(array[tmp] > array[j]){
				tmp = j;
			}
		}
		swap(&array[i], &array[tmp]);
		tmp = i+1;
	}
	return;
}
void BubbleSort(int *array, int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(array[i]>array[j]) swap(&array[i], &array[j]);
		}
	}
	return;
}

void InsertionSort(int *array, int n){
	int tmp;
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(array[j] > array[i]){
				tmp = array[i];
				copy(array+j, array+j+1, i-j);
				array[j] = tmp;
			}
		}
	}
	return;
}
