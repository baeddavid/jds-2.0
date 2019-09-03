#include <emscripten/bind.h>
using namespace emscripten;

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
        exit(EXIT_FAILURE);
    }
    arr[++top] = item;
}

int Stack::pop() {
    if(isEmpty()) {
        exit(EXIT_FAILURE);
    }
    return arr[top--];
}

int Stack::peek() {
    if(isEmpty())
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

EMSCRIPTEN_BINDINGS(stack) {
  class_<Stack>("Stack")
    .constructor<int>()
    .function("push", &Stack::push)
    .function("pop", &Stack::pop)
    .function("peek", &Stack::peek)
    .function("size", &Stack::size)
    .function("isEmpty", &Stack::isEmpty)
    .function("isFull", &Stack::isFull)
    ;
}