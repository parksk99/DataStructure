#ifndef BAG_H
#define BAG_H
#include"../../headerFile/arrayUtil.h"
#include"../../headerFile/header.h"
template<typename T>
class Bag{
	friend ostream& operator<<(ostream& os, const Bag& b){
		for(int i=0; i<=b.top; i++){
			os<<b.array[i]<<" ";
		}
		os<<endl;
		return os;
	}
	protected:
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

/*		Bag(const Bag& ref){
			cout<<"Bag의 복사연산자"<<endl;
			top = ref.top;
			capacity = ref.capacity;
			array = new T[capacity];
			for(int i=0; i<=top; i++){
				array[i] = ref.array[i];
			}
		}
*/
		virtual int Size() const{
			return top + 1;
		}

		virtual bool IsEmpty() const{
			if(top == -1) return true;
			else return false;
		}

		virtual T& Element() const{
			if(IsEmpty()) throw "Bag is empty";
			else return array[top];
		}


		virtual void Push(const T& a){
			if(capacity == top+1)
				ChangeSize1D(array, capacity, capacity*2);
			array[++top] = a;
		}

		virtual void Pop(){
			if(IsEmpty()) throw "Bag is empty";
			int delIndex = top/2;
			copy(array + delIndex +1, array + top +1, array + delIndex);
			array[top--].~T();
		}
};
#endif
