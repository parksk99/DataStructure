#ifndef POLINOMIAL_HPP
#define POLINOMIAL_HPP
#include"../../headerFile/header.h"
#include"circularChain.hpp"
class Polinomial;
struct Term{
	int coef;
	int exp;
	Term(){
		coef = 0;
		exp = -1;
	}
	Term Set(int theCoef = 0, int theExp = -1){
		coef = theCoef; exp = theExp; return *this;}
	Term& operator=(Term& ref){
		coef = ref.coef; exp = ref.exp;
		return *this;
	}
	friend ostream& operator<<(ostream& os, Term& t){
		os<<t.coef<<'x'<<t.exp;
		return os;
	}
};

class Polinomial{
	friend ostream& operator<<(ostream& os, Polinomial& p){
		CircularChain<Term>::ChainIterator i = p.poly.Begin();
		for(;i!=NULL; i++){
			os<<*i<<" ";
		}
		os<<endl;
		return os;
	}
	private:
		CircularChain<Term> poly;
	public:
		Polinomial();
		Polinomial(const Polinomial& p);
		void Add(int c, int e);
		
		Polinomial operator+(Polinomial& b);
};

#include"polinomial.cpp"
#endif
