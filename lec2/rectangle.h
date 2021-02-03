#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"header.h"
class Rectangle;
ostream& operator<<(ostream&, Rectangle&);
class Rectangle{
	private:
		int xLow, yLow, height, width;
		friend ostream& operator<<(ostream&, Rectangle&);
	public:
		Rectangle(int, int, int, int);
		~Rectangle();
		int GetHeight();
		int GetWidth();
		bool operator==(Rectangle&);
};
#endif
