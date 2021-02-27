#ifndef STACK_H
#define STACK_H
#include"../../headerFile/arrayUtil.h"
#include"../../header.h"
template<typename T>
class Stack;
template<typename T>
void PrintSome(const Stack<T>&);
template<typename T>
class Stack{
	template<typename K>
	friend ostream& operator<<(ostream&, const Stack<K>&);
	friend void PrintSome<>(const Stack<T>&);
	private:
		int capacity;
		int top;
		T* stack;
	public:
		Stack(int theCapacity = 10) : capacity(theCapacity){
			top = -1;
			stack = new T[capacity];
		}
		~Stack(){
			delete[] stack;
		}

		inline bool IsEmpty() const{
			return top==-1;
		}

		inline T& Top() const{
			if(IsEmpty()) throw "stack is empty";
			else return stack[top];
		}

		void Push(const T& item){
			if(capacity == top+1){ ChangeSize1D(stack, capacity, 2*capacity); capacity *= 2; }
			stack[++top] = item;
		}

		void Pop(){
			if(IsEmpty()) throw "stack is empty";
			else{
				stack[top--].~T();
			}
		}
		void Imerge(Stack& st1, Stack& st2){
			int newSize = st1.top+1 + st2.top+1;
			if(st1.capacity < newSize) ChangeSize1D(st1.stack, st1.capacity, newSize*2);
			copy(st2.stack, st2.stack+ st2.top+1, st1.stack+ st1.top+1);
			st1.top = newSize-1;
		}
};

template<typename T>
ostream& operator<<(ostream& os, const Stack<T>& st){
	for(int i=st.top; i>=0; i--){
		os<<"|\t"<<st.stack[i]<<"\t|"<<std::endl;
	}
	os<<"---------------"<<std::endl;
	return os;
}

template<typename T>
void PrintSome(const Stack<T>& some){
	std::cout<<some.stack[0];
}
#endif
