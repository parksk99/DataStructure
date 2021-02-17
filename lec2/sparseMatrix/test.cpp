#include"../../header.h"
#include"sparseMatrix.h"
int main(){
	cout<<"Create SparseMatrix a"<<endl;
	SparseMatrix a;
	cout<<"Create Sparsematrix b"<<endl;
	SparseMatrix b;
//	cout<<a;
//	cout<<b;
//	cout<<a.Transpose();
//	cout<<endl;
//	SparseMatrix fastTranspose(a.FastTranspose() );
	cout<<"Mutilply a,b"<<endl;
	SparseMatrix mutiply = a.Multiply(b);
//	cout<<fastTranspose;
	cout<<mutiply;
	return 0;
}

