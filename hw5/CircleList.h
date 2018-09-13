#ifndef CIRCLELIST_H
#define CIRCLELIST_H

template <typename Object>
class CircleList{
public:
	CircleList();				//constructor
	~CircleList();				//destructor
	bool empty() const;			//is list empty?
	const Object& front() const;		//return front element
	const Object& back() const;		//return back element
	void advance();				//advance cursor
	void add(const Object& e);		//add after cursor
	void remove();				//remove after cursor

private:
	struct CNode{				//node struct
		Object elem;
		CNode* next;
	};

	CNode* cursor;				//head of list
};

#include "CircleList.cpp"
#endif
