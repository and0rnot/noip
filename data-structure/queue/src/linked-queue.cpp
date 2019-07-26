#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

typedef struct Node {
    string data;
    struct Node* next;
} *NodePtr, Node;

NodePtr head = NULL;
NodePtr tail = NULL;

void enqueue(string s) {
    if (head == NULL) {
        head = new Node;
        head->data = s;
        head->next = NULL;
        tail = head;
    } else {
        NodePtr tmp = new Node;
        tmp->data = s;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tmp;
    }
}

string dequeue() {
    if (head != NULL) {
        string ret;
        NodePtr tmp = head;
        ret = tmp->data;
        head = head->next;
        delete tmp;
        if (head == NULL)
            tail = NULL;
        return ret;
    } else {
        return "";
    }
}

int main() {
    int n;
    int x = 0;
    while (cin >> n) {
        if (n == 9)
            break;

        if (n == 1) {
            x++;
            char a[64];
            sprintf(a, "color%d", x);
            enqueue(a);
        }

        if (n == 2) {
            string out = dequeue();
            if (out == "")
                cout << "dequeue err" << endl;
            else
                cout << out << endl;
        }
    }
    return 0;
}