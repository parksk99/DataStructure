#include"queue.h"
#include"../../headerFile/header.h"
int main(){
	Queue<int> queue;
	for(int i=0; i<10; i++) queue.Push(i);
	std::cout<<queue;
	queue.Pop();
	std::cout<<queue;
	queue.Push(100);
	std::cout<<queue;
	queue.Push(100);
	queue.Push(100);
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	queue.Push(100);
	std::cout<<queue;
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	std::cout<<queue;

	return 0;
}
