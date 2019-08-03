#include <iostream>
using namespace std;

typedef struct BtNode{
    struct BtNode* left;
    int data;
    struct BtNode* right;
} BtNode, *BTree;

void PreOrder(BTree r) {
    if (r == NULL)
        return;

    cout << r->data << " ";
    PreOrder(r->left);
    PreOrder(r->right);
}

void InOrder(BTree r) {
    if (r == NULL)
        return;

    InOrder(r->left);
    cout << r->data << " ";
    InOrder(r->right);
}

void PostOrder(BTree r) {
    if (r == NULL)
        return;

    PostOrder(r->left);
    PostOrder(r->right);
    cout << r->data << " ";
}

BTree CreateTree() {
    BTree root = new BtNode;
    root->data = 1;
    
    root->left = new BtNode;
    root->left->data = 2;
    root->left->right = NULL;

    root->right = new BtNode;
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    root->left->left = new BtNode;
    root->left->left->data = 4;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    
    return root;
}

int main() {
    BTree root = CreateTree();
    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    return 0;
}