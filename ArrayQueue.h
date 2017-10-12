#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

template <typename Object>
class ArrayQueue
{
    enum {DEF_CAPACITY = 100};

    public:
        // constructor
        ArrayQueue(int cap=DEF_CAPACITY);
        
        // destructor
        ~ArrayQueue();

        // return number of elements
        int size() const;

        // return true if empty, otherwise false
        bool empty() const;

        // return a const reference to the front object
        // return runtime error if queue is empty
        const Object& front() const;

        // insert an object at the back of queue
        void enqueue(const Object& e);

        // remove an object at the front of queue
        void dequeue();

        // print elements of queue
        void printQ();
	
	// find an element in the queue
	bool inQueue(Object e);
    private:
        Object* Q;      // array of queue elements
        int capacity;   // queue capacity
        int f;          // index front  
        int r;          // index rear
        int n;          // current number of elements of queue
};

#include "ArrayQueue.tcc"
#endif 
