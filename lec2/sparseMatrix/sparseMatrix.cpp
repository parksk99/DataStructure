#include"sparseMatrix.h"

static int InputInt(const char* str){
	cout<<str;
	int tmp;
	cin>>tmp;
	return tmp;
}

SparseMatrix::SparseMatrix(){
	rows = InputInt("행렬의 행의 개수 : ");
	cols = InputInt("행렬의 열의 개수 : ");
	terms = InputInt("terms : ");
	capacity = terms;
	smArray = new MatrixTerm[capacity];
}

SparseMatrix::SparseMatrix(int theRows, int theCols, int theTerms){
	rows = theRows; cols = theCols;
	terms = theTerms;
	capacity = terms;
	smArray = new MatrixTerm[capacity];
}

SparseMatrix::SparseMatrix(const SparseMatrix& b){
	rows = b.rows;
	cols = b.cols;
	terms = b.terms;
	capacity = b.capacity;
	for(int i=0; i<terms; i++) smArray[i] = b.smArray[i];
}
	
SparseMatrix SparseMatrix::Transpose(){
	SparseMatrix b(cols, rows, terms);
	int pos=0;
	for(int c=0; c<cols; c++){
		for(int i=0; i<terms; i++){
			if(smArray[i].col==c){
				b.smArray[pos].row = smArray[i].col;
				b.smArray[pos].col = smArray[i].row;
				b.smArray[pos++].value = smArray[i].value;
			}
		}
	}
	return b;
}

SparseMatrix SparseMatrix::FastTranspose(){
	SparseMatrix b(cols, rows, terms);
	int rowSize[cols];
	int rowStart[cols];
	for(int i=0; i<cols; i++) rowSize[i] = 0;
	for(int i=0; i<cols; i++) rowSize[smArray[i].col]++;
	rowStart[0] = 0;
	for(int i=1; i<cols; i++) rowStart[i] = rowStart[i-1] + rowSize[i-1];
	for(int i=0; i<terms; i++){
		int j = rowStart[smArray[i].col];
		b.smArray[j].row = smArray[i].col;
		b.smArray[j].col = smArray[i].row;
		b.smArray[j].value = smArray[i].value;
		rowStart[smArray[i].col]++;
	}
//	delete[] rowSize;
//	delete[] rowStart;
	return b;
}
/*void SparseMatrix::Print(){
	for(int i=0; i<terms; i++)
	cout<<smArray[i].row<<"행 "<<smArray[i].col<<"열 "<<smArray[i].value<<endl;
}
*/
MatrixTerm::MatrixTerm(){
	row = InputInt("row : ");
	col = InputInt("col : ");
	value = InputInt("value : ");
}
/*
MatrixTerm::MatrixTerm(){
}*/

MatrixTerm MatrixTerm::operator=(const MatrixTerm& b){
	row = b.row;
	col = b.col;
	value = b.value;
	return *this;
}

ostream& operator<<(ostream& os, const SparseMatrix& sm){
	for(int i=0; i<sm.terms; i++){
		os<<endl<<sm.smArray[i].row<<"행 "<<sm.smArray[i].col<<"열 "<<sm.smArray[i].value<<endl;
	}
	return os;
}
