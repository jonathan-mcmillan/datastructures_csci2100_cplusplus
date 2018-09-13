#include "ArrayQueue.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// consturctor
template <typename Object>
ArrayQueue<Object>::ArrayQueue(int cap)
    : Q(new Object[cap]), capacity(cap), f(0), r(-1), n(0) {}
        
// destructor
template <typename Object>
ArrayQueue<Object>::~ArrayQueue() {
    delete[] Q;
}

// return number of elements
template <typename Object>
int ArrayQueue<Object>::size() const{
    return n;
}

// return true if empty, otherwise false
template <typename Object>
bool ArrayQueue<Object>::empty() const{
    return n == 0;
}

// return a const reference to the front object
// return runtime error if queue is empty
template <typename Object>
const Object& ArrayQueue<Object>::front() const{
    if (empty()) throw runtime_error("Access to empty queue");
    return Q[f];
}

// insert an object at the back of queue
template <typename Object>
void ArrayQueue<Object>::enqueue(const Object& e) {
    if (size() == capacity) throw runtime_error("Queue overflow");
    r = (r + 1) % capacity;
    Q[r] = e;
    n++;
}

// remove an object at the front of queue
template <typename Object>
void ArrayQueue<Object>::dequeue() {
    if (empty()) throw runtime_error("Access to empty queue");
    f = (f + 1) % capacity;
    n--;
}

// print queue
template <typename Object>
void ArrayQueue<Object>::printQ() {
    cout << "Queue: ";
    for (int i=0; i<n; i++) {
        int index = (f + i) % capacity;
        cout << Q[index] << " ";
    }
    cout << endl;
}

//Check if an element is in the queue
template <typename Object>
bool ArrayQueue<Object>::inQueue(Object e){
    for(int i=0; i<n; i++){
	if(Q[i] == e){
	    return true;
	}
    }
    return false;
}
