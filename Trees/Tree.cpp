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
        node *getSucc(node);
    public:
        Tree();
        void insert(int);
        void printPreOrder(node *);
        void printInOrder(node *);
        void printPostOrder(node *);
        int findMin();
        int findMax();
        bool contains();
        bool *deleteNode(int);
        node *getRoot();
};

Tree::Tree() {
    root = NULL;
    nItems = 0;
}

node *Tree::*getSucc(node *subRoot) {
    node *succParent = new node;
    node *succ = new node;
    node *current = new node;

    succParent = subRoot;
    succ = subRoot;
    current = subRoot -> right;

    while(current != nullptr) {
        succParent = succ;
        succ = current;
        current = current -> left;
    }

    if(succ != subRoot -> right) {
        succParent -> left = succ -> right;
        succ -> right = subRoot -> right;
    }
    return succ;
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

bool *Tree::deleteNode(int key) {
    node *current = new node;
    node *parent = new node;
    current = root;

    bool isLeftChild = true;

    while(current -> data != key) {
        parent = current;
        if(key < current -> data) {
            isLeftChild = true;
            current = current -> left;
        } else {
            isLeftChild = false;
            current = current -> right;
        }
        if(current == nullptr) return NULL;

        if(current -> left == nullptr && current -> right == nullptr) {
            if(current == root)
                root = NULL;
            else if(isLeftChild)
                parent -> left = NULL;
            else 
                parent -> right = NULL;
        }

        else if(current -> right == nullptr) {
            if(current == root)
                root = current -> left;
            else if(isLeftChild)
                parent -> left = current -> left;
            else
                parent -> right = current -> left;
        }

        else if(current -> left == nullptr) {
            if(current == root)
                root = current -> right;
            else if(isLeftChild)
                parent -> left = current -> right;
            else
                parent -> right = current -> right;
        }

        else {
            node *succ = getSucc(*current);
            if(current == root) root = succ;
            else if(isLeftChild)
                parent -> left = succ;
            else
                parent -> right = succ;
            succ -> left = current -> left;
        }
    }
    return NULL;
}

node *Tree::getRoot() {
    return root;
};