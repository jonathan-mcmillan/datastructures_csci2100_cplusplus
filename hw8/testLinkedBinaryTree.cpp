#include <iostream>
#include "LinkedBinaryTree.h"

int main(){
	LinkedBinaryTree<int> tree1;
	LinkedBinaryTree<int> tree2;

	tree1.addRoot(9);
	tree1.addLeftLeaf(tree1.root(), 7);
	tree1.addRightLeaf(tree1.root(), 11);
	tree1.addLeftLeaf(tree1.root().left(), 3);
	tree1.addRightLeaf(tree1.root().left(), 8);
	tree1.addLeftLeaf(tree1.root().right(), 10);
	tree1.addRightLeaf(tree1.root().right(), 14);
	tree1.addLeftLeaf(tree1.root().left().left(), 2);
	tree1.addRightLeaf(tree1.root().left().left(), 5);
	
	tree2.addRoot(9);
        tree2.addLeftLeaf(tree2.root(), 7);
        tree2.addRightLeaf(tree2.root(), 11);
        tree2.addLeftLeaf(tree2.root().left(), 3);
        tree2.addRightLeaf(tree2.root().left(), 8);
        tree2.addLeftLeaf(tree2.root().right(), 10);
        tree2.addRightLeaf(tree2.root().right(), 14);
        tree2.addLeftLeaf(tree2.root().left().left(), 2);
        tree2.addRightLeaf(tree2.root().left().left(), 100);

	cout << "Preorder tree 1: " << endl;
	tree1.preorderPrint();
	
	cout << endl <<  "Preorder tree 2: " << endl;
	tree2.preorderPrint();
	
	cout << endl << "Inorder tree 1: " << endl;
	tree1.inorderPrint();
	
	cout << endl << "Inorder tree 2: " << endl;
	tree2.inorderPrint();

	cout << endl << "Postorder tree 1: " << endl;
	tree1.postorderPrint();
	
	cout << endl << "Postorder tree 2: " << endl;
	tree2.postorderPrint();

	cout << endl << "Is tree 1 a binary tree?" << endl;
	if(tree1.isBST()){
		cout << endl << "Tree is BST" << endl;
	}
	else{
		cout << endl << "Tree is not BST" << endl;
	}

	cout << endl << "Is tree 2 a binary tree?" << endl;
        if(tree2.isBST()){
                cout << endl << "Tree is BST" << endl;
        }
        else{
                cout << endl << "Tree is not BST" << endl;
        }

}
