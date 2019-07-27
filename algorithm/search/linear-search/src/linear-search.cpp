#include <iostream>
using namespace std;

int linear_search(int a[], int len, int key) {
    for (int i = 0; i < len; i++) {
        if (a[i] == key)
            return i;
    }

    return -1;
}

int main() {
    int a[] = {10, 50, 30, 70, 80, 60, 20, 90, 40};
    int ret = linear_search(a, sizeof(a)/sizeof(a[0]), 20);
    if (ret < 0)
        cout << "not found" << endl;
    cout << "at: " << ret << endl;
    return 0;
}