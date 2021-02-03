int Ackermann(int m, int n){
	if(m==0) return n+1;
	else if(n==0) Ackermann(m-1, 1);
	else{
		Ackermann(m-1, Ackermann(m, n-1));
	}
}

//int Ackermann(int m, int n){
	
