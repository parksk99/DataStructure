#include"../../header.h"
#include"sparseMatrix.h"
int main(){
	SparseMatrix a;
//	SparseMatrix b(3);
	cout<<a;
	cout<<a.Transpose();
	cout<<endl;
	SparseMatrix c(a.FastTranspose());
	cout<<c;
	return 0;
}

