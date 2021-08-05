#include"../../header.h"
#include"binaryTree.hpp"
int main(){
	int a[7] = {1,2,3,4,5,6,7};
	Tree<int> tree(a,7);
	tree.Inorder();
	return 0;
}
