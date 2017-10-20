#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "CircleList.h"

template <typename Object>
class LinkedQueue{
public:
	LinkedQueue();				//constructo
	int size() const;			//number of items in stack
	bool empty() const;			//is the queue empty?
	const Object& front() const;		//get the front element
	void enqueue(const Object& e);		//push element onto stack
	void dequeue();				//pop the stack
	void printQ();				//print elements of queue

private:
	CircleList<Object> C;			//linked list of elements
	int n;					//number of elements
};

#include "LinkedQueue.cpp"
#endif
