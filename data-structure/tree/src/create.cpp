#include <iostream>
using namespace std;

typedef struct BtNode{
    struct BtNode* left;
    char c;
    struct BtNode* right;
} BtNode, *Tree;

void PostOrder(Tree r) {
    if (r == NULL)
        return;

    PostOrder(r->left);
    PostOrder(r->right);
    cout << r->c << " ";
}

// input: AB#D##C##
void CreateTree(Tree& r) {
    char c;
    cin >> c;
    if (c == '#') {
        r = NULL;
        return;
    }
    
    r = new BtNode;
    r->c = c;
    CreateTree(r->left);
    CreateTree(r->right);
}

void CreateTree2(Tree* r) {
    char c;
    cin >> c;
    if (c == '#') {
        *r = NULL;
        return;
    }
        
    *r = new BtNode;
    (*r)->c = c;
    CreateTree2(&((*r)->left));
    CreateTree2(&((*r)->right));
}

int main() {
    Tree root;
    //CreateTree(root);
    CreateTree2(&root);
    PostOrder(root);
    cout << endl;
    return 0;
}