#include"header.h"
//#include"NaturalNumber.h"

class NaturalNumber{
    private:
        int n;
    public:
        static NaturalNumber Zero();
        static bool IsZero(NaturalNumber);
        static bool Equal(NaturalNumber, NaturalNumber);
        static NaturalNumber Add(NaturalNumber, NaturalNumber);
        static NaturalNumber Successor(NaturalNumber);
        static NaturalNumber Subtract(NaturalNumber, NaturalNumber);
        static NaturalNumber Multiply(NaturalNumber, NaturalNumber);
        static NaturalNumber Divide(NaturalNumber, NaturalNumber);
        NaturalNumber(int);
        int getN();
};


NaturalNumber::NaturalNumber(int num=0) { n = num; }
int NaturalNumber::getN() { return n; }

NaturalNumber NaturalNumber::Zero(){ return NaturalNumber(0);}

bool NaturalNumber::IsZero(NaturalNumber x){
	if(x.getN() == 0) return true;
}

bool NaturalNumber::Equal(NaturalNumber x, NaturalNumber y){
	if(x.getN() == y.getN()) return true;
	else false;
}

NaturalNumber NaturalNumber::Add(NaturalNumber x, NaturalNumber y){
	if(x.getN() + y.getN() > INT8_MAX) return NaturalNumber(INT8_MAX);
	else return NaturalNumber(x.getN() + y.getN());
}

NaturalNumber NaturalNumber::Successor(NaturalNumber x){
	if(x.getN() ==INT8_MAX) return NaturalNumber(x.getN());
	else return NaturalNumber(x.getN()+1);
}

NaturalNumber NaturalNumber::Subtract(NaturalNumber x, NaturalNumber y){
	if(x.getN() < y.getN()) return NaturalNumber();
	else return NaturalNumber(x.getN() - y.getN());
}

NaturalNumber NaturalNumber::Multiply(NaturalNumber x, NaturalNumber y){
	if(x.getN() * y.getN() > INT8_MAX) return NaturalNumber(INT8_MAX);
	else return NaturalNumber(x.getN() * y.getN());
}

NaturalNumber NaturalNumber::Divide(NaturalNumber x, NaturalNumber y){
	if(x.getN() < y.getN()) return NaturalNumber(0);
	else return NaturalNumber(x.getN() / y.getN());
}

int main(){
	NaturalNumber a(10);
	std::cout<<"a : "<<a.getN()<<std::endl;
	std::cout<<"a + a : "<<NaturalNumber::Add(a, a).getN()<<std::endl;
	return 0;
}
