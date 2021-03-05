#ifndef QUEUE_H
#define QUEUE_H
#include"../../headerFile/header.h"
template<typename T>
class Queue;

template<typename T>
ostream& operator<<(ostream& os, Queue<T> q);

template<typename T>
class Queue{
	template<typename K>
	friend ostream& operator<<(ostream& os, Queue<K> q);
	private:
		int capacity;
		int front, rear;
		T* queue;
	public:
		Queue(int theCapacity = 10);
		Queue(const Queue<T>&);
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
