#ifndef CPPARRAY_H
#define CPPARRAY_H
#include<iostream>
class CppArray;
class CppArray{
	private:
		float* array;
		int size;
		friend std::ostream& operator<<(std::ostream&, CppArray&);
		friend std::istream& operator>>(std::istream&, CppArray&);
	public:
		CppArray(int, float);
		~CppArray();
		CppArray(const CppArray&);
		CppArray& operator=(const CppArray&);
		float& operator[](int);
		int GetSize();
};

std::ostream& operator<<(std::ostream&, CppArray&);
std::istream& operator>>(std::istream&, CppArray&);
#endif
