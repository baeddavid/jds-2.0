#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class LinkedList {
    private:
        node *head, *tail;
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
};

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
    nItems = 0;
}

void LinkedList::insertFirst(int item) {
    node *newLink = new node;
    newLink -> data = item;
    newLink -> next = head;
    head = newLink;
    nItems++;
}

void LinkedList::insertLast(int item) {
    node *newLink = new node;
    newLink -> data = item;
    tail -> next = newLink;
    tail = newLink;
    nItems++;
}

void LinkedList::insertAt(int index, int item) {
    node *newLink = new node;
    node *current = new node;
    node *prev = new node;
    
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
    node *current = new node;
    current = head;

    while(current != NULL) {
        cout<<current -> data<<" ";
        current = current -> next;
    }
}

int LinkedList::removeFirst() {
    node *deleteNode = new node;
    deleteNode = head;
    head = head -> next;
    int value = deleteNode -> data;
    delete deleteNode;
    nItems--;
    return value;
}

int LinkedList::removeLast() {
    node *current = new node;
    node *prev = new node;
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
    node *current = new node;
    node *prev = new node;
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