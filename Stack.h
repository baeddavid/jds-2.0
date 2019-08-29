#include <iostream>
using namespace std;

#define SIZE 10
class Stack {
    private:
        int *arr;
        int top;
        int capacity;

    public:
        Stack(int size = SIZE);
        void push(int);
        int pop();
        int peek();
        int size();
        bool isEmpty();
        bool isFull();
};

Stack::Stack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
}

void Stack::push(int item) {
    if(isFull()) {
        cout<<"STACK OVERFLOW";
        exit(EXIT_FAILURE);
    }
    arr[++top] = item;
}

int Stack::pop() {
    if(isEmpty()) {
        cout<<"STACK UNDERFLOW";
        exit(EXIT_FAILURE);
    }
    return arr[top--];
}

int Stack::peek() {
    if(isEmpty())
        cout<<"STACK IS EMPtY";
    return arr[top];
}

int Stack::size() {
    return top + 1;
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == capacity - 1;
}