#include<iostream>
class A{
	private:
		int a;
		friend std::ostream& operator<<(std::ostream&, A&);
	public:
		A(int tmp = 0) : a(tmp){};
		A(A& tmp){
			a = tmp.a;
		}
		A& f(){
			return A(100);
		}
};

std::ostream& operator<<(std::ostream& os, A& ref){
	os<<ref.a;
	return os;
}
int main(){
	A a(10);
	A &b(a);
//	std::cout<<b;
	std::cout<<b.f();
	
	return 0;
}
