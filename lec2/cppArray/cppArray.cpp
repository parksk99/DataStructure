#include"cppArray.h"
CppArray::CppArray(int s = 5, float initValue = 0){
	size = s;
	array = new float[size];
	for(int i=0; i<size; i++) array[i] = initValue;
}
CppArray::~CppArray(){
	delete[] array;
}

CppArray::CppArray(const CppArray& cp2){
	size = cp2.size;
	array = new float[size];
	for(int i=0; i<size; i++) array[i] = cp2.array[i];
}

CppArray& CppArray::operator=(const CppArray& cp2){
	delete[] array;
	size = cp2.size;
	array = new float[size];
	for(int i=0; i<size; i++) array[i] = cp2.array[i];
	return *this;
}

float& CppArray::operator[](int i){
	if(i>=0 && i<size){
		return array[i];
	}
	else{
		throw "invalid index";
	}
}

int CppArray::GetSize(){
	return size;
}

std::ostream& operator<<(std::ostream& os, CppArray& cp){
	os<<"{";
	for(int i=0; i<cp.size; i++){
		os<<cp.array[i]<<" ";
	}
	os<<"}"<<std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, CppArray& cp){
	for(int i=0; i<cp.size; i++){
		is>>cp.array[i];
	}
	return is;
}
