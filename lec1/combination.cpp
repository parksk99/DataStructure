/*int Combination(int n, int m){
	if(n==m || m==0){
		return 1;
	}
	else if(n<m){
		return -1;
	}
	else{
		return Combination(n-1, m-1) + Combination(n-1, m);
	}
}*/

int Combination(int n, int m){
	int a = 1;
	int b = 1;
	if(n==m) return 1;
	else if(m==0) return 1;
	for(int i=n; i>m; i--){
		a *= i;
	}
	for(int i=1; i<=m; i++){
		b *= i;
	}
	return a/b;
}
