#include"../../headerFile/header.h"
#include"templateChain.hpp"

int main(){
	Chain<int>a;
	a.Insert(13);
	a.Insert(20);
	a.Insert(30);
	std::cout<<a<<std::endl;
	a.Delete(2);
	
	return 0;
}
