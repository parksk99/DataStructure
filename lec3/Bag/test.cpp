#include"bag.h"
int main(){
	Bag<int> a;
	a.Push(3);
	std::cout<<a.Element()<<std::endl;
	std::cout<<a.Size()<<std::endl;
	a.Pop();
	return 0;
}
