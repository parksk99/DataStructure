#include"polinomial.h"
#include"header.h"
int main(){
	Polinomial a(1);
	a.Init(3);
	cout<<a<<endl;

	Polinomial b(1);
	b.Init(3);
	cout<<b<<endl;

	a.Add(b).Print();
	return 0;
}
