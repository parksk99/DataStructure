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

SparseMatrix::SparseMatrix(int theTerms){
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
	SparseMatrix b(terms);
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
void SparseMatrix::Print(){
	for(int i=0; i<terms; i++)
	cout<<smArray[i].row<<"행 "<<smArray[i].col<<"열 "<<smArray[i].value<<endl;
}

MatrixTerm::MatrixTerm(){
	row = InputInt("row : ");
	col = InputInt("col : ");
	value = InputInt("value : ");
}
/*
MatrixTerm::MatrixTerm(){
}*/

MatrixTerm MatrixTerm::operator=(MatrixTerm& b){
	row = b.row;
	col = b.col;
	value = b.value;
	return *this;
}
