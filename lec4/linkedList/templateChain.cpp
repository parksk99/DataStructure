template<typename T>
ChainNode<T>* Chain<T>::asl;
template<typename T>
ChainNode<T>::ChainNode(T newData, ChainNode<T>* newLink)
	: data(newData), link(newLink) {}

	template<typename T>
	ChainNode<T>::~ChainNode(){
		delete link;
	}

template<typename T>
Chain<T>::Chain(){
	first = 0;
	last = 0;
	size = 0;
}

template<typename T>
Chain<T>::~Chain(){
	if(asl){
		last->link = asl;
	}
	asl = first;
	first = 0;
	last = 0;
}

	template<typename T>
Chain<T>::ChainIterator::ChainIterator(ChainNode<T>* start)
	: current(start){}

	template<typename T>
	T& Chain<T>::ChainIterator::operator*() const{
		return current->data;
	}

template<typename T>
T* Chain<T>::ChainIterator::operator->() const{
	return &(current->data);
}

/*template<typename T>
Chain<T>::ChainIterator& Chain<T>::ChainIterator::operator++(){
	current = current -> link;
	return *this;
}

template<typename T>
ChainIterator Chain<T>::ChainIterator::operator++(int){
	ChainIterator tmp = *this;
	current = current -> link;
	return tmp;
}*/

template<typename T>
bool Chain<T>::ChainIterator::operator!=(ChainNode<T>* x){
	return current!=x;
}


template<typename T>
void Chain<T>::Insert(T newData){
	if(first){
		last->link = GetNode();
		last = last->link;
		last->data = newData;
	}
	else{
		first = GetNode();
		first->data = newData;
		last = first;
	}
	size++;
}

template<typename T>
void Chain<T>::Delete(int i){
	if(i>=size) {
		std::cout<<"Delete index is bigger than Chain size("<<size<<")"<<std::endl;
		return;
	}
	else if(i<0) {
		std::cout<<"Delete index must be bigger than 0"<<std::endl;
		return;
	}
	else if(i==0){
		ChainNode<T>* tmp = first;
		first = first->link;
		tmp->link = 0;
		ReturnNode(tmp);
		if(size==1) { last = 0; }
	}
	else{
		ChainNode<T>* tmp = first;
		ChainNode<T>* prev = 0;
		for(int j = 0; j<i; j++){
			prev = tmp;
			tmp = tmp->link;
		}
		prev->link = tmp->link;
		tmp->link = 0;
		ReturnNode(tmp);
		if(prev->link == 0) last = prev;
	}
	size--;
}

template<typename T>
ChainNode<T>* Chain<T>::GetNode(){
	if(asl){
		ChainNode<T>* tmp = asl;
		asl = asl->link;
		tmp->link = 0;
		//tmp->data = 0;
		return tmp;
	}
	else{
		return new ChainNode<T>;
	}
}

template<typename T>
void Chain<T>::ReturnNode(ChainNode<T>* x){
	x->link = asl;
	asl = x;
}

template<typename T>
T Chain<T>::Get(int i){
	ChainIterator it = Begin();
	for(int j=0; j<i; j++){ it++;}
	return *it;
}

/*template<typename T>
Chain<T>::ChainIterator Chain<T>::Begin(){
	return ChainIterator(first);
}

template<typename T>
ChainIterator Chain<T>::End(){
	return ChainIterator(0);
}*/
