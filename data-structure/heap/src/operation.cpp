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
    int i = g_hp.num;
    while (i/2 > 0 && g_hp.data[i] > g_hp.data[i/2]) { // from bottom to top
        swap(g_hp.data[i], g_hp.data[i/2]);
        i = i / 2;
    }
}

void remove() {
    // check empty
    if (g_hp.num == 0) {
        cout << "empty" << endl;
        return;
    }

    // replace top by the tail
    g_hp.data[1] = g_hp.data[g_hp.num];
    g_hp.num--;

    // heapify from top to bottom
    int i = 1;
    while (1) {
        int larger_pos = i;
        if (i*2 <= g_hp.num && g_hp.data[larger_pos] < g_hp.data[i*2])
            larger_pos = i*2;
        if (i*2+1 <= g_hp.num && g_hp.data[larger_pos] < g_hp.data[i*2+1])
            larger_pos = i*2+1;
        if (larger_pos == i)
            break;

        swap(g_hp.data[i], g_hp.data[larger_pos]);
        i = larger_pos;
    }
}

void show() {
    for (int i = 1; i <= g_hp.num; i++)
        cout << g_hp.data[i] << " ";
    cout << endl;
}

int main() {
    int value;
    while (cin >> value) {
        insert(value);
    }

    show();
    remove();
    show();

    return 0;
}