#include"../../headerFile/arrayUtil.h"
#include"bag.h"
template<typename T>
Bag<T>::Bag(int theCapacity) : capacity(theCapacity){
	if(capacity <1) throw "capacity must be > 0";
	array = new T[capacity];
	top = -1;
}

template<typename T>
Bag<T>::~Bag(){
	delete[] array;
}

template<typename T>
int Bag<T>::Size() const{
	return top;
}

template<typename T>
bool Bag<T>::isEmpty() const{
	if(top == -1) return true;
	else return false;
}

template<typename T>
T& Bag<T>::Element() const{
	if(isEmpty()) throw "Bag is empty";
	else return array[top];
}

template<typename T>
void Bag<T>::Push(const T& a){
	if(capacity == top+1)
		ChangeSize1D(array, capacity, capacity*2);
	array[++top] = a;
}

template<typename T>
void Bag<T>::Pop(){
	if(isEmpty()) throw "Bag is empty";
	int delIndex = top/2;
	copy(array + delIndex +1, array + top +1, array + delIndex);
	array[top--].~T();
}
