#include <iostream>
#include <string>
#include <deque>
using namespace std;

void print(deque<double> deq, string name)
{
    deque<double>::iterator it;

    cout << name << ": ";

    for(it = deq.begin(); it != deq.end(); ++it)
        cout << *it << " ";

    cout << endl;
}

int main() 
{
    double array[10] = {3.45, 67, 10, 0.67, 8.99, 9.78, 6.77, 34.677, 10.25, 89.76};
    deque<double> deq(array, array + 10);
    deque<double>::iterator it;
    print(deq, "deq");

    // remove the last element of the deque
    deq.pop_back();
    print(deq, "deq");

    // remove the first element of the deque
    deq.pop_front();
    print(deq, "deq");

    // erase the third element of the deque
    it = deq.begin();
    it += 2;
    deq.erase(it);
    print(deq, "deq");

    // remove all elements from the deque
    deq.clear();

    if(deq.empty())
        cout << "deq is empty" << endl;

    // Output
    // deq: 3.45 67 10 0.67 8.99 9.78 6.77 34.677 10.25 89.76
    // deq: 3.45 67 10 0.67 8.99 9.78 6.77 34.677 10.25
    // deq: 67 10 0.67 8.99 9.78 6.77 34.677 10.25
    // deq: 67 10 8.99 9.78 6.77 34.677 10.25
    // deq is empty

    return 0;
}
