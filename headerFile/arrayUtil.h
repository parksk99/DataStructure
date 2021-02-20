#ifndef ARRAY_UTIL_H
#define ARRAY_UTIL_H
template<class T>
void copy(T*, T*, T*);

template<class T>
void ChangeSize1D(T* a, const int oldSize, const int newSize){
	if(newSize < 0) throw "New size must be >= 0";

	T* tmp = new T[newSize];
	int number = oldSize<newSize?oldSize:newSize;
	copy(a, a+number, tmp);
	delete[] a;
	a = tmp;
}
//1차원 배열의 크기를 바꿔줌

template<class T>
void swap(T& a, T& b){
	int tmp = a;
	a = b;
	b = tmp;
}
//a와 b의 위치를 바꿈

template<class T>
void copy(T* start, T* end, T* newPos){
	if(start > end) throw "must be start < end";
	int i = 0;
	while(start + i != end){
		newPos[i] = start[i];
		i++;
	}
}
//start부터 end까지 newPos위치로 옮김
#endif
