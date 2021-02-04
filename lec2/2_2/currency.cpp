#include"header.h"
#include"currency.h"
Currency::Currency(int d = 0, int s = 0)
	:dollar(d), cents(s) { }
Currency::~Currency() {}

void Currency::setDollar(int d) { dollar = d;}
void Currency::setCents(int s) { cents = s;}
int Currency::getDollar(){ return dollar; }
int Currency::getCents(){ return cents;}

Currency Currency::operator+(Currency& c){
	int tmpCents = cents + c.cents;
	int tmpDollar = dollar + c.dollar;
	if(tmpCents>=100){
		tmpDollar++;
		tmpCents-=100;
	}
	return Currency(tmpDollar, tmpCents);
}

ostream& operator<<(ostream& os, Currency& c){
	os<<c.getDollar()<<"$ "<<c.getCents()<<"cents"<<endl;
	return os;
}

Currency Currency::operator+(int d){
	dollar+=d;
	return Currency(dollar, cents);
}

Currency Currency::operator-(Currency& c){
	int tmpDollar = dollar - c.dollar;
	int tmpCents = cents - c.cents;
	if(tmpDollar < 0) {
		tmpDollar--;
		tmpCents += 100;
	}
	return Currency(tmpDollar, tmpCents);
}
