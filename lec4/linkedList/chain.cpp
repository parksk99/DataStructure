#include"../../headerFile/header.h"
template<typename T>
class ChainNode;

template<typename T>
class Chain;

template<typename T>
class ChainNode{
	friend Chain<T>;
	template<typename K>
	friend ostream& operator<<(ostream& os, Chain<K>& ref);
	private:
	int data;
	ChainNode<T>* link;
	public:
	ChainNode(T newData=0, ChainNode<T>* next = 0)
		: data(newData),link(next){ }
};

template<typename T>
class Chain{
	class ChainIterator{
		private:
			ChainNode<T>* current;
		public:
			ChainIterator(ChainNode<T>* start){
				current = start;
			}
			ChainIterator& operator++(){
				current = current -> link;
				return *this;
			}
			ChainIterator operator++(int){
				ChainIterator tmp = *this;
				current = current -> link;
				return tmp;
			}
			T& operator*() const {
				return current->data;
			}
			T* operator->() const {
				return &(current->data);
			}
	};

	template<typename K>
	friend ostream& operator<<(ostream& os, Chain<K>& ref){
		ChainNode<T>* tmp = ref.first;
		while(tmp){
			os<<tmp->data<<" ";
			tmp = tmp->link;
		}
		os<<endl;
		return os;
	}
	private:
	ChainNode<T>* first;
	public:
	Chain() : first(NULL){ }
	void Create(T newData);
	void Insert(T newData){
		if(first){
			first->link = new ChainNode<T>(newData, first->link);
		}
		else{
			first = new ChainNode<T>(newData, 0);
		}
	}
	ChainIterator begin() const {return ChainIterator(first);}
	ChainIterator end() const { return 0;}
};

int main(){
	Chain<int> a ;
	a.Insert(10);
	a.Insert(20);
	a.Insert(30);
	a.Insert(40);
	cout<<a;
	return 0;
}
