int BinarySearch(int *array, const int x, const int n){
	int left = 0;
	int right = n-1;
	int middle = n/2;
	while(left != right && array[middle] != x){
		if(array[middle] > x){
			right = middle-1;
		}
		else{ left = middle+1; }
		middle = (left+right)/2;
	}
	if(array[middle] == x) return middle;
	else return -1;
}

int RecursiveBinarySearch(int *array, const int x, const int left, const int right){
	int middle = (left+right)/2;
	if(left<=right){
		if(array[middle] == x) return middle;
		else if(x < array[middle]) RecursiveBinarySearch(array, x, left, middle-1);
		else RecursiveBinarySearch(array, x, middle+1, right);
	}
	else{
		return -1;
	}
}
