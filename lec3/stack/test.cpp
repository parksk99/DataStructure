#include"stack.h"
#include"../../header.h"
int main(){
	Stack<int> stack;
	int a = 10;
	stack.Push(a);
	std::cout<<stack.Top()<<std::endl;
	std::cout<<stack.IsEmpty()<<std::endl;
	stack.Push(11);
	stack.Push(13);
	std::cout<<stack;
	
	Stack<int> stack2;
	stack2.Push(100);
	stack2.Push(101);
	stack.Imerge(stack, stack2);
	std::cout<<stack;

	PrintSome(stack);
	return 0;
}
