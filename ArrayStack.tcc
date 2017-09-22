#include "ArrayStack.h"
#include <stdexcept>
using namespace std;

template <typename Object>
ArrayStack<Object>::ArrayStack(int cap)
    : S(new Object[cap]), capacity(cap), t(-1) {}

template <typename Object>
int ArrayStack<Object>::size() const {
    return ??;
}

template <typename Object>
bool ArrayStack<Object>::empty() const {
    return ??;
}

template <typename Object>
const Object& ArrayStack<Object>::top() const {
    if (empty()) throw runtime_error("Stack is Empty");
    return ??;
}

template <typename Object>
void ArrayStack<Object>::push(const Object& e) {
    if (size() == capacity) throw runtime_error("Stack is Full");
    ??
}

template <typename Object>
void ArrayStack<Object>::pop() {
    if (empty()) throw runtime_error("Stack is Empty");
    ??
}

// ------------------ housekeeping functions follow --------------------

// Copy Constructor
template <typename Object>
ArrayStack<Object>::ArrayStack(const ArrayStack& other)
    : S(new Object[other.capacity]), capacity(other.capacity), t(other.t)
{
    for (int j=0; j <= t; j++)
        S[j] = other.S[j];
}

// Destructor
template <typename Object>
ArrayStack<Object>::~ArrayStack() {
    delete[] S;
}

// Assignment Operator
template <typename Object>
ArrayStack<Object>& ArrayStack<Object>::operator=(const ArrayStack& other) {
    if (this != &other) {
        capacity = other.capacity;
        t = other.t;
        delete[] S;
        S = new Object[capacity];
        for (int j=0; j <= t; j++)
            S[j] = other.S[j];
    }
    return *this;
}
