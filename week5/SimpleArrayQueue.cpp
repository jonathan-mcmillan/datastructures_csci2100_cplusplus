#include<iostream>
using namespace std; 
#define MAX_SIZE 10  //maximum size of the array that will store Queue. 

// Creating a class named Queue.
class Queue
{
private:
    int A[MAX_SIZE];
    int front, rear; 
public:
    // Constructor - set front and rear as -1. 
    Queue() {
        front = -1; 
        rear = -1;
    }

    // To check wheter Queue is empty or not
    bool IsEmpty() {
        return (front == -1 && rear == -1); 
    }

    // To check whether Queue is full or not
    bool IsFull() {
        return (rear+1)%MAX_SIZE == front ? true : false;
    }

    // Inserts an element in queue at rear end
    void Enqueue(int x) {
        cout << "Enqueuing " << x << endl;
        if (IsFull()) throw runtime_error("Error: Queue is Full");

        if (IsEmpty()) {
            front = rear = 0; 
        }
        else {
            rear = (rear+1) % MAX_SIZE;
        }

        A[rear] = x;
    }

    // Removes an element in Queue from front end. 
    void Dequeue() {
        cout << "Dequeuing" << endl;
        if (IsEmpty()) throw runtime_error("Error: Queue is Empty");

        if (front == rear) {
            rear = front = -1;
        }
        else {
            front = (front+1) % MAX_SIZE;
        }
    }

    // Printing the elements in queue from front to rear. 
    void Print()
    {
        // Finding number of elements in queue  
        int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
        cout<<"Queue       : ";
        for(int i = 0; i <count; i++) {
            int index = (front+i) % MAX_SIZE; 
            cout << A[index]<<" ";
        }
        cout << endl;
    }
};

int main()
{
   Queue Q; // creating an instance of Queue. 
   Q.Enqueue(2);  Q.Print();  
   Q.Enqueue(4);  Q.Print();  
   Q.Enqueue(6);  Q.Print();
   Q.Dequeue();      Q.Print();
   Q.Enqueue(8);  Q.Print();
}

