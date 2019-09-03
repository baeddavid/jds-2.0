#include <iostream>
using namespace std;

#define SIZE 10

class Queue {
    private:
        int *arr;
        int front;
        int rear;
        int capacity;
    
    public:
        Queue(int size = SIZE);
        void enque(int);
        int deque();
        int peek();
        int size();
        bool isEmpty();
        bool isFull();
};

Queue::Queue(int size) {
    arr = new int[size];
    capacity = size + 1;
    front = 0;
    rear = -1;
}

void Queue::enque(int item) {
    if(isFull()) {
        cout<<"QUEUE OVERFLOW";
        exit(EXIT_FAILURE);
    }
    if(rear == capacity - 1) rear = -1;
    arr[++rear] = item;
}

int Queue::deque() {
    if(isEmpty()) {
        cout<<"QUEUE UNDERFLOW";
        exit(EXIT_FAILURE);
    }
    int returnVal = arr[front++];
    if(front == capacity) front = 0;
    return returnVal;
}

int Queue::peek() {
    if(isEmpty())
        cout<<"QUEUE IS EMPTY";
    return arr[front];
}

int Queue::size() {
    if(rear >= front)
        return rear - front + 1;
    else
        return (capacity - front) + (rear - 1);
}

bool Queue::isEmpty() {
    return (rear + 1 == front || (front + capacity - 1 ==rear));
}

bool Queue::isFull() {
    return (rear + 2 == front || (front + capacity - 2 == rear));
}