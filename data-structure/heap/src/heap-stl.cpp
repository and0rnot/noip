#include <iostream>
#include <algorithm>
using namespace std;

const int kMax = 100;

struct Heap {
    int data[kMax+1];
    int num;
};

struct Heap g_hp;

void insert(int value) {
    // check full
    if (g_hp.num >= kMax) {
        cout << "full" << endl;
        return;
    }

    // store to the heap tail
    g_hp.num++;
    g_hp.data[g_hp.num] = value;

    // heapify process
    push_heap(g_hp.data+1, g_hp.data+g_hp.num+1);
}

void remove() {
    // check empty
    if (g_hp.num == 0) {
        cout << "empty" << endl;
        return;
    }

    // heapify from top to bottom
    pop_heap(g_hp.data+1, g_hp.data+g_hp.num+1);
    g_hp.num--;
}

void show() {
    for (int i = 1; i <= g_hp.num; i++)
        cout << g_hp.data[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    g_hp.num = n;
    for (int i = 1; i <= n; i++)
        cin >> g_hp.data[i];

    make_heap(g_hp.data+1, g_hp.data+g_hp.num+1);

    show();
    int a;
    cin >> a;
    insert(a);
    show();
    remove();
    show();

    return 0;
}