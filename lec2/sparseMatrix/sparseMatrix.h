#include"../../header.h"
class SparseMatrix;
class MatrixTerm;
class SparseMatrix{
	private:
		MatrixTerm *smArray;
		int rows, cols, terms, capacity;
	public:
		SparseMatrix();
		SparseMatrix(int);
		SparseMatrix(const SparseMatrix&);
		SparseMatrix Transpose();
		void Print();
};

class MatrixTerm{
	friend class SparseMatrix;
	private:
		int row, col, value;
	public:
		MatrixTerm();
		MatrixTerm operator=(MatrixTerm&);
};
