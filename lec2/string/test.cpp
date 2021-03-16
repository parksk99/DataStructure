#include"string.h"
int main(){
	String a("eababcde", 7);
	cout<<"a의 길이 : "<<a.Length()<<endl;
	cout<<"a가 공백이다? : "<<!a<<endl;
	cout<<"String a : "<<a<<endl;

	String b("abc", 3);
	cout<<"String b : "<<b<<endl;
	String c = a.Concat(b);
	cout<<"String a.Concat(b) : "<<c<<endl;
	
	cout<<"c.Substr(3,3) : "<<c.Substr(3, 3)<<endl;

	cout<<"a.Find(b) : "<<a.Find(b)<<endl;
	cout<<"a.FastFind(b) : "<<a.FastFind(b)<<endl;
	return 0;
}
