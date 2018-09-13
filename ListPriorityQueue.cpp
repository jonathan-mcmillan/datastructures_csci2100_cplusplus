template <typename E, typename C> // number of elements
int ListPriorityQueue<E,C>::size() const {
	return L.size();
}

template <typename E, typename C> // is the queue empty?
bool ListPriorityQueue<E,C>::empty() const {
	return L.empty();
}

template <typename E, typename C> // insert element
void ListPriorityQueue<E,C>::insert(const E& e) {
	typename std::list<E>::iterator p;
	p = L.begin();
	while(p != L.end() && !IsLess(e, *p)){
		++p;
	}
	L.insert(p, e);
}

template <typename E, typename C> // minimum element
const E& ListPriorityQueue<E,C>::min() const {
	return L.front();
} 

template <typename E, typename C> // remove minimum
void ListPriorityQueue<E,C>::removeMin() {
    if (L.size() > 0) {
        L.pop_front();
    } else {
        cout << "error" << endl;
    }
}
