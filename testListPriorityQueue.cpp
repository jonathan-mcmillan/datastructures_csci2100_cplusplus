#include <iostream>
#include "ListPriorityQueue.h"

using namespace std;

class IsLess {
public:
	bool operator()(const
};

int main() {
    ListPriorityQueue<int, IsLess> myLPQ;
    myLPQ.insert(5);
    myLPQ.insert(9);
    myLPQ.insert(2);
    myLPQ.insert(7);
    cout << myLPQ.min() << endl;
    myLPQ.removeMin();
    cout << myLPQ.size() << endl;
    cout << myLPQ.min() << endl;
    myLPQ.removeMin();
    myLPQ.removeMin();
    myLPQ.removeMin();
    cout << (myLPQ.empty() == 1 ? "true" : "false")  << endl;
    myLPQ.removeMin();

    return 0;
}
