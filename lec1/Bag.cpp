#include<iostream>
class Bag{
	private:
	int* bag;
	int capacity;
	int count;
	public:
	~Bag(){
		delete bag;
	}

	void Create(int n){
		bag = new int[n];
		capacity = n;
	}

	void Insert(int x){
		if(count > capacity) {
			std::cout<<"too much"<<std::endl;
			return;
		}
		else{
			bag[count++] = x;
			return;
		}
	}

	void Remove(int x){
		for(int i=0; i<count; i++){
			if(bag[i] == x){
				for(int j=i; j<count; j++){
					bag[j] = bag[j+1];
				}
				count--;
//				return;
			}
		}
		std::cout<<"babo"<<std::endl;
		return;
	}

	bool IsIn(int x){
		for(int i=0; i<count; i++){
			if(bag[i] == x) return true;
		}
		return false;
	}
	
	void print(){
		for(int i=0; i<count; i++) std::cout<<bag[i]<<" ";
		std::cout<<std::endl;
	}
};

int main(){
	Bag bag;
	bag.Create(10);
	bag.Insert(5);
	bag.print();
	bag.Insert(6);
	bag.print();
	if(bag.IsIn(6)) std::cout<<"good"<<std::endl;
	bag.Insert(5);
	bag.print();
	bag.Remove(6);
	bag.print();
	if(bag.IsIn(6)) std::cout<<"good"<<std::endl;
	else std::cout<<"good2"<<std::endl;
	bag.Remove(5);

	bag.print();
	if(bag.IsIn(5)) std::cout<<"good"<<std::endl;
	bag.Remove(10);
	
	return 0;
}
