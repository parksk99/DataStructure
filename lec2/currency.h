#ifndef CURRENCY_H
#define CURRENCY_H
#include"header.h"
class Currency;
class Currency{
	private:
		int dollar, cents;
	public:
		Currency(int, int);
		~Currency();
		void setDollar(int d);
		void setCents(int s);
		int getDollar();
		int getCents();
		Currency operator+(Currency&);
		Currency operator+(int);
		Currency operator-(Currency&);
};
ostream& operator<<(ostream&, Currency&);
#endif
