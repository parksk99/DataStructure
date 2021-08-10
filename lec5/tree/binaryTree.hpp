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
		~Tree();
		Tree(const Tree<T>&);
		void Inorder();
		void Inorder(TreeNode<T>*);
		void Preorder();
		void Preorder(TreeNode<T>*);
		void Postorder();
		void Postorder(TreeNode<T>*);
		void NonrecInorder();
		class Iterator{
			public:
				Iterator(){ currentNode = root; q.push(root);}
				TreeNode<T>* Next();

			private:
				TreeNode<T>* currentNode;
				std::queue<TreeNode<T>*> q;
		};
		TreeNode<T>** FindPosition(){
//			std::queue<TreeNode<T>*> q;
			TreeNode<T>* current;
//			position.push(current);
			while(!position.empty()){
				current = position.front();
				if(current->leftChild){
					position.push(current->leftChild);
				}
				else{
					return &(current->leftChild);
				}
				if(current->rightChild){
					position.push(current->rightChild);
				}
				else{
					position.pop();
					return &(current->rightChild);
				}
			}
		}
};
#include"binaryTree.cpp"
#endif
