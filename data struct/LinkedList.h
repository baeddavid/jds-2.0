#include<iostream>
using namespace std;

struct link {
    int data;
    link *next;
};

class LinkedList {
    private:
        link *head, *tail;
        int nItems;
        
    public:
        LinkedList();
        void insertFirst(int);
        void insertLast(int);
        void insertAt(int, int);
        void displayList();
        int removeFirst();
        int removeLast();
        int removeAt(int);
        int size();
        int top();
};

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
    nItems = 0;
}

void LinkedList::insertFirst(int item) {
    link *newLink = new link;
    newLink -> data = item;
    newLink -> next = head;
    head = newLink;
    nItems++;
}

void LinkedList::insertLast(int item) {
    link *newLink = new link;
    newLink -> data = item;
    tail -> next = newLink;
    tail = newLink;
    nItems++;
}

void LinkedList::insertAt(int index, int item) {
    link *newLink = new link;
    link *current = new link;
    link *prev = new link;
    
    current = head;
    for(int i = 0; i <= index; i++) {
        prev = current;
        current = current -> next;
    }
    newLink -> data = item;
    prev -> next = newLink;
    newLink -> next = current;
    nItems++;
}

void LinkedList::displayList() {
    link *current = new link;
    current = head;

    while(current != NULL) {
        cout<<current -> data<<" ";
        current = current -> next;
    }
}

int LinkedList::removeFirst() {
    link *deletelink = new link;
    deletelink = head;
    head = head -> next;
    int value = deletelink -> data;
    delete deletelink;
    nItems--;
    return value;
}

int LinkedList::removeLast() {
    link *current = new link;
    link *prev = new link;
    current = head;

    while(current -> next != NULL) {
        prev = current;
        current = current -> next;
    }
    tail = prev;
    prev -> next = NULL;
    int value = current -> data;
    delete current;
    nItems--;
    return value;
}

int LinkedList::removeAt(int index) {
    link *current = new link;
    link *prev = new link;
    current = head;

    for(int i = 0; i < index; i++) {
        prev = current;
        current = current -> next;
    }
    int value = current -> data;
    prev -> next = current -> next;
    nItems--;
    return value;
}

int LinkedList::size() {
    return nItems;
}

int LinkedList::top() {
    return head -> data;
}