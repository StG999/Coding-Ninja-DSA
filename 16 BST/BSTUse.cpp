#include <iostream>
#include "BSTClass.h"

using namespace std;

int main()
{
    BST b;
    b.insertNode(5);
    b.insertNode(3);
    b.insertNode(6);
    b.insertNode(2);
    b.insertNode(4);
    b.insertNode(8);
    b.insertNode(1);
    b.insertNode(7);
    b.insertNode(9);

    // b.increasingBST();
    b.printTree();
}