#ifndef LISTPRIORITYQUEUE_H
#define LISTPRIORITYQUEUE_H

#include <list>

using namespace std;

template <typename E, typename C>
class ListPriorityQueue {
public:
	int size() const;
	bool empty() const;
	void insert(const E& e);
	const E& min() const;
	void removeMin();
private:
	std::list L;
	C isLess;
};

#include "ListPriorityQueue.cpp"
#endif
