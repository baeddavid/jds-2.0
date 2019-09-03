#include "data struct/LinkedList.h"
#include <emscripten/bind.h>
using namespace emscripten;

class LinkedStack {
    private:
        LinkedList list;
        int capacity;
    
    public:
        LinkedStack();
        void push(int);
        int pop();
        int peek();
        int size();
        bool isEmpty();
};

LinkedStack::LinkedStack() {
    capacity = 0;
}

void LinkedStack::push(int item) {
    list.insertFirst(item);
}

int LinkedStack::pop() {
    if(isEmpty())
        exit(EXIT_FAILURE);
    return list.removeFirst();
}

int LinkedStack::peek() {
    if(isEmpty())
        return list.top();
}

int LinkedStack::size() {
    return list.size();
}

bool LinkedStack::isEmpty() {
    return list.size() == 0;
}

EMSCRIPTEN_BINDINGS(stack) {
  class_<LinkedStack>("Stack")
    .constructor<>()
    .function("push", &LinkedStack::push)
    .function("pop", &LinkedStack::pop)
    .function("peek", &LinkedStack::peek)
    .function("size", &LinkedStack::size)
    .function("isEmpty", &LinkedStack::isEmpty)
    ;
}