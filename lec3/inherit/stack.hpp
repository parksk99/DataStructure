template<typename T>
Stack<T>::Stack(int stackCapacity)
	: Bag<T>(stackCapacity){}

template<typename T>
Stack<T>::~Stack(){}

//template<typename T>
//Stack<T>::Stack(const Stack& ref)
//{std::cout<<"Stack의 복사연산자"<<endl;
//}

template<typename T>
void Stack<T>::Pop(){
	if(this->IsEmpty()) throw "Stack is empty. Can't Pop";
	this->top--;
}

template<typename T>
T& Stack<T>::Top() const{
	return this->array[this->top];
}
