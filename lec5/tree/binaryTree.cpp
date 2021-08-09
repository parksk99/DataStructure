template<typename T>
TreeNode<T>::TreeNode(){
	data = 0;
	leftChild = rightChild = NULL;
}

template<typename T>
TreeNode<T>::TreeNode(T theData){
	data = theData;
	leftChild = rightChild = NULL;
}

template<typename T>
TreeNode<T>::TreeNode(const TreeNode<T>& ref){
	data = ref.data;
	leftChild = ref.leftChild;
	rightChild = ref.rightChild;
}

template<typename T>
TreeNode<T> TreeNode<T>::operator=(const TreeNode<T>& ref){
	if(leftChild) delete leftChild;
	if(rightChild) delete rightChild;
	data = ref.data;
	leftChild = ref.leftChild;
	rightChild = ref.rightChild;
	return *this;
}

template<typename T>
Tree<T>::Tree(){
	root = NULL;
}

template<typename T>
Tree<T>::Tree(T* data, int n){
	root = new TreeNode<T>(data[0]);
	position.push(root);
	for(int i=1; i<n; i++){
		TreeNode<T> **tmp = FindPosition();
		*tmp = new TreeNode<T>(data[i]);
		/*TreeNode<T>* curr = position.front();
		if(curr->leftChild==NULL){
			curr->leftChild = new TreeNode<T>(data[i]);
			position.push(curr->leftChild);
		}
		else if(curr->rightChild == NULL){
			curr->rightChild = new TreeNode<T>(data[i]);
			position.push(curr->rightChild);
			position.pop();
		}
		else{
			curr = position.front();
			curr->leftChild = new TreeNode<T>(data[i]);
			position.push(curr->leftChild);
		}*/
	}
}

template<typename T>
Tree<T>::~Tree(){
	std::queue<TreeNode<T>*> q;
	TreeNode<T>* current = root;
	q.push(current);
	while(!q.empty()){
		current = q.front();
		if(current->leftChild){
			q.push(current->leftChild);
		}
		if(current->rightChild){
			q.push(current->rightChild);
		}
		q.pop();
		delete[] current;
	}
}

template<typename T>
void Tree<T>::Inorder(){
	Inorder(root);
}

template<typename T>
void Tree<T>::Inorder(TreeNode<T>* current){
	if(current){
		Inorder(current->leftChild);
		std::cout<<current->data<<" ";
		Inorder(current->rightChild);
	}
}

template<typename T>
void Tree<T>::Preorder(){
	Preorder(root);
}

template<typename T>
void Tree<T>::Preorder(TreeNode<T>* current){
	if(current){
		std::cout<<current->data<<" ";
		Preorder(current->leftChild);
		Preorder(current->rightChild);
	}
}

template<typename T>
void Tree<T>::Postorder(){
	Postorder(root);
}

template<typename T>
void Tree<T>::Postorder(TreeNode<T>* current){
	if(current){
		Postorder(current->leftChild);
		Postorder(current->rightChild);
		std::cout<<current->data<<" ";
	}
}

template<typename T>
void Tree<T>::NonrecInorder(){
	Stack<TreeNode<T>*> s;
	TreeNode<T>* current = root;
	while(true){
		while(current){
			s.push(current);
			current = current-> leftChild;
		}
		if(s.IsEmpty()) return;
		current = s.Top();
		s.Pop();
		std::cout<<current->data<<" ";
		current = current -> rightChild;
	}
}

/*template<typename T>
  T* Tree<T>::Iterator::Next(){
  whlie(true){
  if(currentNode ->leftChild){
  q.Push(currentNode -> leftChild);
  }
  if(currentNode -> rightChild){
  q.Push(currentNode -> rightChild);
  }
  }
  if(q.IsEmpty()) return 0;
  q.Pop();
  T& tmp = currentNode-> data;
  currentNode = q.Front();
  return &tmp
  }*/
