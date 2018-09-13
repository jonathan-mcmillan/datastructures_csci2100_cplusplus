#include "ArrayQueue.h"
#include <iostream>

using namespace std;

int main()
{
    ArrayQueue<int> A;
    A.enqueue(7); A.printQ();
    A.enqueue(5); A.printQ();
    A.enqueue(3); A.printQ();
    A.enqueue(1); A.printQ();
    A.dequeue(); A.printQ();
    A.dequeue(); A.printQ();

    ArrayQueue<string> B(5);
    B.enqueue("John"); B.printQ();
    B.enqueue("Ricardo"); B.printQ();
    B.enqueue("Eric"); B.printQ();
    B.enqueue("Claire"); B.printQ();
    B.enqueue("Mambi"); B.printQ();
    //B.enqueue("Echo"); B.printQ();
    B.dequeue(); B.printQ();
    B.dequeue(); B.printQ();

    ArrayQueue<int> C = A;
    cout << "Queue A: "; A.printQ() ;
    cout << "Queue C: "; C.printQ() ;
    C.dequeue();
    cout << "Queue A: "; A.printQ() ;
    cout << "Queue C: "; C.printQ() ;

    return 0;
}
