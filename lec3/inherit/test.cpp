#include<iostream>
#include"stack.h"
int main(){
	Bag<int> bag;
	bag.Push(9);
	bag.Push(8);
	bag.Push(5);
	bag.Push(5);
	bag.Push(5);
	bag.Push(5);
	bag.Push(5);
	bag.Push(5);
	bag.Push(5);
	bag.Push(5);
	bag.Push(5);
	bag.Push(5);
	bag.Push(6);
	bag.Push(6);
	std::cout<<bag;

	Stack<int> stack;
	stack.Push(5);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	stack.Push(6);
	std::cout<<stack;
	std::cout<<stack.Size();
	return 0;
}
