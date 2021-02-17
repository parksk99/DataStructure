#include"../../header.h"
class SparseMatrix;
class MatrixTerm;
class SparseMatrix{
	friend ostream& operator<<(ostream&, const SparseMatrix&);
	private:
		MatrixTerm *smArray;
		int rows, cols, terms, capacity;
	public:
		SparseMatrix();
		SparseMatrix(int, int ,int);
		SparseMatrix(const SparseMatrix&);
		SparseMatrix Transpose();
		SparseMatrix FastTranspose() const;
		SparseMatrix Multiply(const SparseMatrix&);
		void StoreSum(const int sum, const int theRow, const int theCol);
		void Change1D(const int newSize);
};

class MatrixTerm{
	friend class SparseMatrix;
	friend ostream& operator<<(ostream&, const SparseMatrix&);
	private:
		int row, col, value;
	public:
		MatrixTerm();
		MatrixTerm operator=(const MatrixTerm&);
};

ostream& operator<<(ostream& os, const SparseMatrix&);
