#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H

#include <iostream>
#include <list>
#include <queue>

using namespace std;

template <typename Object>
class LinkedBinaryTree {

protected:

	struct Node{
		Object elem;
		Node* parent;
		Node* left;
		Node* right;
		Node() : elem(), parent(NULL), left(NULL), right(NULL) { }
		Node(Object& e) : elem(e), parent(NULL), left(NULL), right(NULL) { }
	};

public:
	class Position{
	private:
		Node* v;
	public:
		Position(Node* _v = NULL) : v(_v) { }
		Object& operator*() { return v -> elem; }
		Position left() const { return Position(v->left); }
		Position right() const { return Position(v-> right); }
		Position parent() const { return Position(v->parent); }
		bool isRoot() const { return v-> parent == NULL; }
		bool isExternal() const { return v->left == NULL && v->right == NULL; }
		bool isNull() {return (v == NULL); }
		friend class LinkedBinaryTree;
	};

public:
	LinkedBinaryTree();
	int size() const;
	bool empty() const;
	bool isBST() const;
	Position root() const;
	void addRoot(const Object& value = Object());
	void addLeftLeaf(const Position& p, const Object& value);
	void addRightLeaf(const Position& p, const Object& value);
	void preorderPrint() const;
	void inorderPrint() const;
	void postorderPrint() const;
	void expandExternal(const Position& p);
	Position removeAboveExternal(const Position& p);

protected:

private:
	void preorder(const Node* v) const;
	void inorder(const Node* v) const;
	void postorder(const Node* v) const;
	void inorderQueue(const Node* v) const;
	queue<int> inorderQ;
	Node* _root;
	int n;
};

#include "LinkedBinaryTree.cpp"
#endif
