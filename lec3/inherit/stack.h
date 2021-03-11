#pragma once
#include"bag.h"

template<typename T>
class Stack : public Bag<T>{
	public:
		Stack(int stackCapacity = 10);
		~Stack();
		Stack(const Stack&);

		void Pop();
		T& Top() const;
};
#include"stack.hpp"
