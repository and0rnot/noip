#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
    string data;
    struct Node* next;
} *NodePtr, Node;

NodePtr head = nullptr;
NodePtr tail = nullptr;

void enqueue(string s) {
    if (head == nullptr) {
        head = new Node;
        head->data = s;
        head->next = nullptr;
        tail = head;
    } else {
        NodePtr tmp = new Node;
        tmp->data = s;
        tmp->next = nullptr;
        tail->next = tmp;
        tail = tmp;
    }
}

string dequeue() {
    if (head != nullptr) {
        string ret;
        NodePtr tmp = head;
        ret = tmp->data;
        head = head->next;
        delete tmp;
        if (head == nullptr)
            tail = nullptr;
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
            string s = "color" + to_string(x);
            enqueue(s);
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