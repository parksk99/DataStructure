#ifndef BAG_H
#define BAG_H
#include"../../headerFile/arrayUtil.h"
#include"../../headerFile/header.h"
template<typename T>
class Bag{
	private:
		int capacity;
		int top;
		T* array;
	public:
		Bag(int theCapacity = 10) : capacity(theCapacity){
			if(capacity <1) throw "capacity must be > 0";
			array = new T[capacity];
			top = -1;
		}

		~Bag(){
			delete[] array;
		}

		int Size() const{
			return top + 1;
		}

		bool isEmpty() const{
			if(top == -1) return true;
			else return false;
		}

		T& Element() const{
			if(isEmpty()) throw "Bag is empty";
			else return array[top];
		}


		void Push(const T& a){
			if(capacity == top+1)
				ChangeSize1D(array, capacity, capacity*2);
			array[++top] = a;
		}

		void Pop(){
			if(isEmpty()) throw "Bag is empty";
			int delIndex = top/2;
			copy(array + delIndex +1, array + top +1, array + delIndex);
			array[top--].~T();
		}
};
#endif
