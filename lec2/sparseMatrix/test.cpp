#include"../../header.h"
#include"sparseMatrix.h"
int main(){
	SparseMatrix a;
//	SparseMatrix b(3);
	a.Print();
	cout<<endl;
	SparseMatrix c(a.Transpose());
	c.Print();
	return 0;
}

