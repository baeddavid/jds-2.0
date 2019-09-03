#include<iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
    node *parent;
};

class Tree {
    private:
        node *root;
        int nItems;
    public:
        Tree();
        void insert(int);
        void printPreOrder(node *);
        void printInOrder(node *);
        void printPostOrder(node *);
        int findMin();
        int findMax();
        bool contains();
        node *deleteNode(int);
        node *getRoot();
};

Tree::Tree() {
    root = NULL;
    nItems = 0;
}

void Tree::insert(int item) {
    node *newNode = new node;
    newNode -> data = item;
    newNode -> left = NULL;
    newNode -> right = NULL;
    if(!root) root = newNode;
    else {
        node *current = new node;
        node *parent = new node;
        current = root;
        while(true) {
            parent = current;
            if(item < current -> data) {
                current = current -> left;
                if(!current) {
                    parent -> left = newNode;
                    return;
                }
            } else {
                current = current -> right;
                if(!current) {
                    parent -> right = newNode;
                    return;
                }
            }
        }
    }
}

void Tree::printPreOrder(node *lRoot) {
    if(lRoot != NULL) {
        cout<<lRoot -> data<<" ";
        printPreOrder(lRoot -> left);
        printPreOrder(lRoot -> right);
    }
};

void Tree::printInOrder(node *lRoot) {
    if(lRoot != NULL) {
        printInOrder(lRoot -> left);
        cout<<lRoot -> data<< " ";
        printInOrder(lRoot -> right);
    }
};

void Tree::printPostOrder(node *lRoot) {
    if(lRoot != NULL) {
        printPostOrder(lRoot -> left);
        printPostOrder(lRoot -> right);
        cout<<lRoot -> data<< " ";
    }
};

node *Tree::getRoot() {
    return root;
};