#include<iostream>
#include"cppArray.h"
int main(){
	CppArray a(10, 3);
	CppArray b(10, 4);
	CppArray c = a;
	b = a;
	std::cout<<"Array a"<<std::endl<<a;
	std::cout<<"Array b"<<std::endl<<b;
	std::cout<<"Array c"<<std::endl<<c;

	std::cout<<a[3]<<std::endl;
	try{
		std::cout<<a[10]<<std::endl;
	}
	catch(const char* e){ std::cout<<e<<std::endl;}

	std::cout<<"size of a : "<<a.GetSize()<<std::endl;
	std::cout<<"input a"<<std::endl;
	std::cin>>a;
	std::cout<<"Array a"<<std::endl<<a;
	return 0;
}

