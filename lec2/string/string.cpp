#include"string.h"
String::String(const char* theStr = "", int theLength = 0){
	length = theLength;
	str = new char[length];
	for(int i=0; i<length; i++){
		str[i] = theStr[i];
	}
	f = new int[length];
	FailureFunction();
}

String::String(const String& ref){
	length = ref.length;
	str = new char[length];
	for(int i=0; i<length; i++) str[i] = ref.str[i];
	f = new int[length];
	FailureFunction();
}

bool String::operator==(String t){
	if(length != t.length) return false;
	for(int i=0; i<length; i++){
		if(str[i] != t.str[i]) return false;
	}
	return true;
}

bool String::operator!(){
	if(length == 0) return true;
	else return false;
}

int String::Length(){
	return length;
}

String String::Concat(String t){
	int currIndexT = 0, currIndex = length;
	String tmpString(str, length+t.length);
	while(currIndexT<t.length){
		tmpString.str[currIndex++] = t.str[currIndexT++];
	}
	return tmpString;
}

String String::Substr(int i, int j){
	String tmpString("", j);
	for(int k=0; k<tmpString.length; k++){
		tmpString.str[k] = str[i+k];
	}
	return tmpString;
}

String String::operator=(const String& t){
	char* tmpStr = new char[t.length];
	for(int i=0; i<t.length; i++)
		tmpStr[i] = t.str[i];
	delete[] str;
	length = t.length;
	str = tmpStr;
	return *this;
}

ostream& operator<<(ostream& os, const String& a){
	for(int i=0; i<a.length; i++)
		os<<a.str[i];
	return os;
}

int String::Find(String pat){
	for(int i=0; i<length; i++){
		int j;
		for(j=0; j<pat.length && str[i+j] == pat.str[j]; j++);
			if(j == pat.length) return i;
	}
	return -1;
}

int String::FastFind(String pat){
	int posS = 0, posP = 0;
	while(posS < length && posP < pat.length){
		if(str[posS] == pat.str[posP]){
			posS++; posP++;
		}
		else{
			if(posP>0){
				posP = pat.f[posP - 1] + 1;
			}
			else{
				posS++;
			}
		}
	}
	if(posP == pat.length) return posS - pat.length;
	else return -1;
}

void String::FailureFunction(){
	f[0] = -1;
	for(int i=1; i<length; i++){
		int prevF = f[i-1];
		while(prevF > 0 && str[i] != str[prevF + 1]){ prevF = f[prevF]; }
		if(str[i] == str[prevF+1]) f[i] = prevF + 1;
		else f[i] = -1;
	}
}
