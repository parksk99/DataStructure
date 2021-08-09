#include"polinomial.hpp"
int main(){
	Polinomial a;
	a.Add(7, 10);
	a.Add(7, 8);
	a.Add(7, 3);
	
	Polinomial b;
	b.Add(3, 9);
	b.Add(3, 8);
	b.Add(3, 1);

	Polinomial c(a+b);
	std::cout<<c;
	return 0;
	//git commit --amend test
}
