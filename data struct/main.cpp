#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "Tree.h"
using namespace std;

int main() {
    Tree t;
    t.insert(4);
    t.insert(3);
    t.insert(8);
    t.insert(-1);
    t.insert(2);
    node *root = t.getRoot();
    t.printPostOrder(root);
}