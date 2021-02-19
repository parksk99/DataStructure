#ifndef STRING_H
#define STRING_H
#include"../../header.h"
class String;

class String{
	friend ostream& operator<<(ostream& os, const String &a);
	//String 클래스의 <<연산자 오버로딩

	private:
		char* str;
		int length;
		int* f;
	public:
		String(const char* theStr, int theLength);
		//길이가 theLength이고 theStr인 String 클래스 생성

		String(const String& ref);
		//복사생성자

		bool operator==(String t);
		//this와 t의 문자열이 같으면 true 다르면 false를 반환

		bool operator!();
		//this가 공백이면 true를 반환 아니면 false를 반환

		int Length();
		//this의 length를 반환

		String Concat(String t);
		//this뒤에 t를 붙여서 반환

		String Substr(int i, int j);
		//this의 i번째원소부터 j개의 String을 반환

		int Find(String pat);
		//this안에 pat이라는 패턴이 있으면 제일 앞 인덱스를 반환
		//this안에 pat이라는 패턴이 없으면 -1반환

		int FastFind(String pat);
		//더 효율적인 Find 알고리즘

		void FailureFunction();
		//FastFind에 필요한 실패함수를 설정
		
		void ChangeSize(int newSize);
		//this의 length를 newSize로 변경

		String operator=(const String& t);
		//this에 t를 deep copy함
};

ostream& operator<<(ostream& os, const String& a);
#endif
