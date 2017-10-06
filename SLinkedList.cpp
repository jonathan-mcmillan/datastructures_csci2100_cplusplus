#include "SLinkedList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename Object>
SLinkedList<Object>::SLinkedList() : head(NULL) {}

template <typename Object>
SLinkedList<Object>::~SLinkedList() {
    while (!empty()) {
        removeFront();
    }
}

template <typename Object>
bool SLinkedList<Object>::empty() const {
    return (head == NULL);
}

template <typename Object>
const Object& SLinkedList<Object>::front() const {
    if (head == NULL) throw runtime_error("Head is NULL");
    return head->elem;
}

template <typename Object>
void SLinkedList<Object>::addFront(const Object& e) {
    SNode* v = new SNode;
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename Object>
void SLinkedList<Object>::removeFront() {
    if (empty()) throw runtime_error("Access to empty list");
    SNode* old = head;
    head = old->next;
    delete old;
}

/*
template <typename Object>
SLinkedList<Object>::SLinkedList(const SLinkedList& other) {
    //travel through other, copying as we go
    SNode* current = other.head;
    SNode* previous = NULL;
    
    while (current != NULL) {
        SNode* temp = new SNode;
        temp->elem = current->elem;
      
        if (previous == NULL) {
            head = temp;
        }
        else {
            previous->next = temp;
        }
        previous = temp;
        current = current->next;
    }

template <typename Object>
SLinkedList<Object>& SLinkedList<Object>::operator=(const SLinkedList& other) {
    if (this != &other) {
    }
    return *this;
}
*/
