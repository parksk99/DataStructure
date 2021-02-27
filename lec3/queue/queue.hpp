#include"../../headerFile/arrayUtil.h"
template<typename T>
Queue<T>::Queue(int theCapacity) : capacity(theCapacity){
	if(capacity < 1) throw "capacity must be > 0";
	front = rear = 0;
	queue = new T[capacity];
	for(int i=0; i<capacity; i++) queue[i] = 0;
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
