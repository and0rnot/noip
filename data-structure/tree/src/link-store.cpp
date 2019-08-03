#include <iostream>
using namespace std;

typedef struct BtNode{
    struct BtNode* lchild;
    int data;
    struct BtNode* rchild;
} BtNode, *BTree;

BTree CreateTree() {
    BTree root = new BtNode;
    root->data = 1;
    
    root->lchild = new BtNode;
    root->lchild->data = 2;
    root->lchild->rchild = NULL;

    root->rchild = new BtNode;
    root->rchild->data = 3;
    root->rchild->lchild = NULL;
    root->rchild->rchild = NULL;

    root->lchild->lchild = new BtNode;
    root->lchild->lchild->data = 4;
    root->lchild->lchild->lchild = NULL;
    root->lchild->lchild->rchild = NULL;
    
    return root;
}

int main() {
    BTree root = CreateTree();
    cout << root->lchild->lchild->data << endl;
    return 0;
}