#ifndef QUEUE_H
#define QUEUE_H
#include"../../headerFile/header.h"
template<typename T>
class Queue;

template<typename T>
class Queue{
	template<typename K>
	friend ostream& operator<<(ostream& os, Queue<K> q){
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
	private:
		int capacity;
		int front, rear;
		T* queue;
	public:
		Queue(int theCapacity = 10);
		//생성자
		bool IsEmpty() const;
		//해당 큐가 비어있는지 확인

		T& Front() const;
		//맨 앞(처음들어온) 원소를 반환

		T& Rear() const;
		//맨 뒤(마지막에 들어온) 원소를 반환

		void Push(const T&);
		//새로운 원소를 큐에 삽입

		void Pop();
		//맨 앞의 원소를 삭제
};
#include"queue.hpp"
#endif
