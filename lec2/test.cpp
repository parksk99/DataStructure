#include"header.h"
#include"rectangle.h"

int main(){
	Rectangle a(1,3,5,6);
	std::cout<<"a height : "<<a.GetHeight()<<std::endl;
	Rectangle b(1,3,4,6);
	if(a==b) std::cout<<"true"<<std::endl;
	else std::cout<<"false"<<std::endl;
	std::cout<<a<<std::endl;
	if(a>b) cout<<"a>b"<<std::endl;
	else cout<<"a<b"<<std::endl;
	return 0;
}
