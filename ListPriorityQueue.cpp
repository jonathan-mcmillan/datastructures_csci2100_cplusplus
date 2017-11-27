template <typename E, typename C> // number of elements
int ListPriorityQueue<E,C>::size() const {

}

template <typename E, typename C> // is the queue empty?
bool ListPriorityQueue<E,C>::empty() const {

}

template <typename E, typename C> // insert element
void ListPriorityQueue<E,C>::insert(const E& e) {

}

template <typename E, typename C> // minimum element
const E& ListPriorityQueue<E,C>::min() const {

} 

template <typename E, typename C> // remove minimum
void ListPriorityQueue<E,C>::removeMin() {
    if (L.size() > 0) {
        L.pop_front();
    } else {
        cout << "error" << endl;
    }
}
