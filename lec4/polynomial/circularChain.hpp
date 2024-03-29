#ifndef TEMPLATE_CHAIN_H
#define TEMPLATE_CHAIN_H
#include"../../headerFile/header.h"
template<typename T>
class CircularChain;

template<typename T>
class ChainNode;

template<typename T>
class ChainNode{
	private:
		friend CircularChain<T>;
		T data;
		ChainNode<T>* link;
	public:
		ChainNode(T newData = T(), ChainNode<T>* newLink = 0);
		~ChainNode();
};

template<typename T>
class CircularChain{
	template<typename K>
	friend ostream& operator<<(ostream& os, CircularChain<K>& chain){
		ChainIterator it;
		for(it = chain.Begin(); it!=0; it++){
			os<<*it<<" ";
		}
		os<<endl;
		return os;
	}

	private:
		int size;
		ChainNode<T>* first;
		ChainNode<T>* last;
		ChainNode<T>* head;
		static ChainNode<T>* asl;//available space list
	public:
		CircularChain();
		~CircularChain();
		CircularChain(const CircularChain<T>&);
		class ChainIterator{
			private:
				ChainNode<T>* current;
			public:
				ChainIterator(ChainNode<T>* start = 0);
				T& operator*() const;
				T* operator->() const;
				ChainIterator& operator++(){
					current = current->link;
					return *this;
				}
				ChainIterator operator++(int){
					ChainIterator tmp = *this;
					current = current->link;
					return tmp;
				}

//				bool operator==();
				bool operator!=(ChainNode<T>*);
		};
		void Insert(T newData);
		void Delete(int i);
		ChainNode<T>* GetNode();
		void ReturnNode(ChainNode<T>* x);
		T Get(int i);
		ChainIterator Begin(){
			return ChainIterator(first);
		}
		ChainIterator End(){
			return ChainIterator(head);
		}
};
#include"circularChain.cpp"
#endif
