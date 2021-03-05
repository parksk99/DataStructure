#include"../../headerFile/arrayUtil.h"
template<typename T>
Queue<T>::Queue(int theCapacity) : capacity(theCapacity){
	if(capacity < 1) throw "capacity must be > 0";
	front = rear = 0;
	queue = new T[capacity];
	for(int i=0; i<capacity; i++) queue[i] = 0;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& ref){
//	cout<<"Queue의 복사연산자 호출"<<endl;
	capacity = ref.capacity;
	front = ref.front; rear = ref.rear;
	queue = new T[capacity];
	for(int i=0; i<capacity; i++) queue[i] = ref.queue[i];
}

template<typename T>
inline bool Queue<T>::IsEmpty() const{
	return rear == front;
}

template<typename T>
inline T& Queue<T>::Front() const{
	if(IsEmpty()) throw "Queue is Empty. There is no front";
	return queue[front];
}

template<typename T>
inline T& Queue<T>::Rear() const{
	if(IsEmpty()) throw "Queue is Empty. There is no rear";
	return queue[rear];
}

template<typename T>
void Queue<T>::Push(const T& item){
	int nextPos = (rear+1) % capacity;
	if(nextPos == front){
		ChangeSize1D(queue, capacity, 2 * capacity);
		//여기서 오류 
		//Queue의 복사연산자를 오버로딩 했더니 오류가 없어짐......?
		//Queue의 복사연산자에 cout 한줄 추가했더니 다시 생김
		//cout없애면 오류도 없어짐
		if(front > rear){
			copy(queue + front + 1, queue + capacity, queue + capacity + front + 1);
			front += capacity;
		}
		capacity *= 2;
		//꽉 찼을 경우
	}
	else{
		rear = nextPos;
		queue[rear] = item;
	}
}

template<typename T>
void Queue<T>::Pop(){
	if(IsEmpty()) throw "Queue is Empty. Cannot pop.";
	front = (front + 1)%capacity;
	queue[front].~T();
}

template<typename K>
ostream& operator<<(ostream& os, Queue<K> q){
		if(q.IsEmpty()) return os;
		os<<"capacity : "<<q.capacity<<" front : "<<q.front<<" rear : "<<q.rear<<endl;
		if(q.front > q.rear){
			for(int i=q.front+1; i<q.capacity; i++) os<<q.queue[i]<<" ";
			for(int i=0; i<=q.rear; i++) os<<q.queue[i]<<" ";
		}
		else{
			for(int i=q.front+1; i<=q.rear; i++) os<<q.queue[i]<<" ";
		}
		os<<std::endl;
		return os;
}
