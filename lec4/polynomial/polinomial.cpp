Polinomial::Polinomial(){
	poly = CircularChain<Term>();
}

Polinomial::Polinomial(const Polinomial& p){
	poly = p.poly;
}

void Polinomial::Add(int c, int e){
	Term tmp;
	poly.Insert(tmp.Set(c,e));
}

Polinomial Polinomial::operator+(Polinomial& b){
	Term tmp;
	Polinomial c;
	CircularChain<Term>::ChainIterator ai = poly.Begin(), bi = b.poly.Begin();
	while(ai!=NULL&&bi!=NULL){
		if(ai->exp > bi->exp){
			c.poly.Insert(*ai);
			ai++;
		}
		else if(ai->exp == bi -> exp){
			int t = ai->coef + bi -> coef;
			if(t){
				c.poly.Insert(tmp.Set(t, ai->exp));
			}
			ai++; bi++;
		}
		else{
			c.poly.Insert(*bi);
			bi++;
		}
	}
	while(ai!=NULL){
		c.poly.Insert(*ai);
		ai++;
	}
	while(bi!=NULL){
		c.poly.Insert(*bi);
		bi++;
	}
	return c;
}
