#include"polinomial.h"
#include"header.h"

Polinomial::Polinomial(int c=1){
	terms = 0;
	capacity = c;
	termArray = new Term[capacity];
}

Polinomial::~Polinomial(){
	delete[] termArray;
}

void Polinomial::Init(int n){
	float tmpCoef, tmpExp;
	for(int i=0; i<n; i++){
		std::cout<<"계수 : ";
		std::cin>>tmpCoef;
		std::cout<<"지수 : ";
		std::cin>>tmpExp;
		NewTerm(tmpCoef, tmpExp);
	}
}

Polinomial Polinomial::Add(Polinomial b){
	int aPos = 0, bPos = 0;
	Polinomial c;
	while((aPos<terms)&&(bPos<b.terms)){
	cout<<"hi"<<endl;
		if(termArray[aPos].exp == b.termArray[bPos].exp){
			float tmpCoef = termArray[aPos].coef + b.termArray[bPos].coef;
			if(tmpCoef) c.NewTerm(tmpCoef, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if(termArray[aPos].exp < b.termArray[bPos].exp){
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else{
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	}
	for(;aPos<terms;aPos++){
	cout<<"hia"<<endl;
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	}
	for(;bPos<b.terms; bPos++){
	cout<<"hib"<<endl;
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
	}
	cout<<"hi2"<<endl;
	return c;
}

void Polinomial::NewTerm(const float theCoef, const int theExp){
	if(capacity==terms){
		capacity *= 2;
		Term *tmp = new Term[capacity];
		copy(termArray, termArray+terms, tmp);
		delete[] termArray;
		termArray = tmp;
	}
	termArray[terms].coef = theCoef;
	termArray[terms++].exp = theExp;
}

Term::Term(float theCoef, int theExp)
	: coef(theCoef), exp(theExp)
{}

Term::~Term(){}

ostream& operator<<(ostream& os, Polinomial& p){
	for(int i=0; i<p.terms; i++){
		cout<<p.termArray[i].coef<<"x"<<p.termArray[i].exp<<" ";
	}
	cout<<endl<<"capacity : "<<p.capacity<<endl<<"terms : "<<p.terms<<endl;
	return os;
}

Polinomial::Polinomial(Polinomial& p){
	capacity = p.capacity;
	termArray = new Term[capacity];
	for(int i=0; i<p.terms; i++){
		NewTerm(p.termArray[i].coef, p.termArray[i].exp);
	}
}

Polinomial Polinomial::operator=(Polinomial& p){
	terms = 0;
	capacity = p.capacity;
	delete[] termArray;
	termArray = new Term[capacity];
	for(int i=0; i<p.terms; i++){
		NewTerm(p.termArray[i].coef, p.termArray[i].exp);
	}
	return *this;
}

Term::Term(Term& t){
	coef = t.coef;
	exp = t.exp;
}

Term Term::operator=(Term& t){
	coef = t.coef;
	exp = t.exp;
}
