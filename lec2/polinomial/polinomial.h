#ifndef POLINOMIAL_H
#define POLINOMIAL_H
#include"header.h"
class Polinomial;
class Term;

class Polinomial{
	friend ostream& operator<<(ostream&, Polinomial&);
	private:
		Term* termArray;
		int capacity;
		int terms;
	public:
		Polinomial(int t);
		~Polinomial();
		Polinomial(Polinomial&);
		Polinomial operator=(Polinomial&);
		Polinomial Add(const Polinomial);
		void Init(int); //입력받음
		void NewTerm(const float theCoef, const int theExp);
};

class Term{
	friend Polinomial;
	friend ostream& operator<<(ostream&, Polinomial&);
	private:
		float coef; //계수
		int exp; //지수
	public:
		Term(float theCoef = 0, int theExp=0);
		~Term();
		Term(Term&);
		Term operator=(Term&);
};
ostream& operator<<(ostream&, Polinomial&);

#endif
