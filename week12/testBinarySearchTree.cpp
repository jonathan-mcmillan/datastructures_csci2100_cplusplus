#include <iostream>
#include "LinkedBinaryTree.h"

int main()
{
    /* create the following binary tree:
                 9
               /   \
              7     11
             / \    / \
            3   8  10  14
           / \
          2   5
    */ 

    LinkedBinaryTree<int> tree;
    tree.addRoot(9);
    tree.addLeftLeaf(tree.root(), 7);
    tree.addRightLeaf(tree.root(), 11);
    tree.addLeftLeaf(tree.root().left(), 3);
    tree.addRightLeaf(tree.root().left(), 8);
    tree.addLeftLeaf(tree.root().right(), 10);
    tree.addRightLeaf(tree.root().right(), 14);
    tree.addLeftLeaf(tree.root().left().left(), 2);
    tree.addRightLeaf(tree.root().left().left(), 5);

    cout << "Preorder:" << endl;
    tree.preorderPrint();

    cout << endl << "Inorder:" << endl;
    tree.inorderPrint();

    cout << endl << "Postorder:" << endl;
    tree.postorderPrint();

    return 0;
}
