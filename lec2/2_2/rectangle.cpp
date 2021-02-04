#include"rectangle.h"
Rectangle::Rectangle(int x = 0, int y = 0, int h = 0, int w=0)
	: xLow(x), yLow(y), height(h), width(w)
{ }

Rectangle::~Rectangle(){}

int Rectangle::GetHeight(){
	return height;
}

int Rectangle::GetWidth(){ return width; }

bool Rectangle::operator==(Rectangle& r){
	if(this == &r) return true;
	else if(xLow == r.xLow && yLow == r.yLow && height == r.height &&width == r.width) return true;
	else return false;
}

ostream& operator<<(ostream& os, Rectangle& r){
	os << "xLow : " << r.xLow << std::endl;
	os << "yLow : " << r.yLow << std::endl;
	os << "width : " << r.width << " height : " << r.height <<std::endl;
	return os;
}

bool Rectangle::operator<(Rectangle& r){
	if(height*width < r.height* r.width) return true;
	else return false;
}

bool Rectangle::operator>(Rectangle& r){
	if(height*width > r.height * r.width) return true;
	else return false;
}
