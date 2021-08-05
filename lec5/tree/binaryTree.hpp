#ifndef BINARY_TREE
#define BINARY_TREE
#include"../../lec3/stack/stack.h"
//#include"../../lec3/queue/queue.h"
#include<queue>
using namespace std;
template<typename T>
class Tree;
template<typename T>
class TreeNode{
	friend class Tree<T>;
	private:
	T data;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
	public:
	TreeNode();
	TreeNode(T);
	TreeNode(const TreeNode<T>&);
	TreeNode<T> operator=(const TreeNode<T>&);
};

template<typename T>
class Tree{
	private:
		TreeNode<T>* root;
		std::queue<TreeNode<T>*> position;
	public:
		Tree();
		Tree(T*, int n);
		void Inorder();
		void Inorder(TreeNode<T>*);
		void Preorder();
		void Preorder(TreeNode<T>*);
		void Postorder();
		void Postorder(TreeNode<T>*);
		void NonrecInorder();
		class Iterator{
			public:
				Iterator(){ currentNode = root;}
				T* Next();
			private:
				TreeNode<T>* currentNode;
				std::queue<TreeNode<T>*> q;
		};
		TreeNode<T>** FindPosition(){
			std::queue<TreeNode<T>*> q;
			TreeNode<T>* current = root;
			q.push(current);
			while(true){
				current = q.front();
				if(current->leftChild){
					q.push(current->leftChild);
				}
				else{
					return &(current->leftChild);
				}
				if(current->rightChild){
					q.push(current->rightChild);
				}
				else{
					return &(current->rightChild);
				}
				q.pop();
			}
		}
};
#include"binaryTree.cpp"
#endif
