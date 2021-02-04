#include"header.h"
#include"currency.h"
#include"rectangle.h"

int main(){
	//Rectangle test
	std::cout<<"Rectangle test"<<std::endl;
	Rectangle a(1,3,5,6);
	std::cout<<"a height : "<<a.GetHeight()<<std::endl;
	Rectangle b(1,3,4,6);
	if(a==b) std::cout<<"true"<<std::endl;
	else std::cout<<"false"<<std::endl;
	std::cout<<"a : ";
	std::cout<<a<<std::endl;
	if(a>b) cout<<"a>b"<<std::endl;
	else cout<<"a<b"<<std::endl;
	
	//Currency test
	std::cout<<std::endl;
	std::cout<<"Currency test"<<std::endl;
	Currency x(2,50);
	Currency y(3, 51);
	cout<<x;

	return 0;
}
