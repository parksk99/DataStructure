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

SparseMatrix SparseMatrix::FastTranspose() const{
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
	return b;
}

SparseMatrix SparseMatrix::Multiply(const SparseMatrix& b){
	if(cols != b.rows) throw "Incompatible Matrices";
	SparseMatrix d(rows, b.cols, 0);
	SparseMatrix bXpos(b.FastTranspose());
	int currRowIndex = 0, currRowBegin = 0, currRowA = smArray[currRowIndex].row;
	if(terms == capacity) Change1D(terms+1);
	bXpos.Change1D(bXpos.terms + 1);
	smArray[terms].row = rows;
	bXpos.smArray[b.terms].row = b.cols;
	bXpos.smArray[b.terms].col = -1;
	int sum = 0;
	while(currRowIndex < terms){
		int currColIndex = 0, currColBegin = 0, currColB = bXpos.smArray[0].row;
		while(currColIndex <= b.terms){
			if(smArray[currRowIndex].row != currRowA){
				d.StoreSum(sum, currRowA, currColB);
				sum = 0;
				while(bXpos.smArray[currColIndex].row == currColB){
					currColIndex++;
				}
				currRowIndex = currRowBegin;
				currColBegin = currColIndex;
				currColB = bXpos.smArray[currColIndex].row;
			}
			else if(bXpos.smArray[currColIndex].row != currColB){
				d.StoreSum(sum, currRowA, currColB);
				sum = 0;
				currRowIndex = currRowBegin;
				currColBegin = currColIndex;
				currColB = bXpos.smArray[currColIndex].row;
			}
			else{
				if(smArray[currRowIndex].col < bXpos.smArray[currColIndex].col){
					currRowIndex++;
				}
				else if(smArray[currRowIndex].col == bXpos.smArray[currColIndex].col){
					sum += smArray[currRowIndex].row * smArray[currColIndex].row;
					currRowIndex++; currColIndex++;
				}
				else{
					currColIndex++;
				}
			}
		}
		while(smArray[currRowIndex].row == currRowA){
			currRowIndex++;
		}
		currRowBegin = currRowIndex;
		currRowA = smArray[currRowIndex].row;
	}

	return d;
}


void SparseMatrix::StoreSum(const int sum, const int theRow, const int theCol){
	if(sum == 0) return;
	else{
		if(terms==capacity){
			Change1D(2*capacity);
		}
		smArray[terms].row = theRow;
		smArray[terms].col = theCol;
		smArray[terms++].value = sum;
	}
}

void SparseMatrix::Change1D(const int newSize){
	if(newSize<terms) throw "New size must be bigger than therms";
	MatrixTerm *tmpArray = new MatrixTerm[newSize];
	for(int i=0; i<terms; i++){
		tmpArray[i] = smArray[i];
	}
	delete[] smArray;
	smArray = tmpArray;
	capacity = newSize;
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
