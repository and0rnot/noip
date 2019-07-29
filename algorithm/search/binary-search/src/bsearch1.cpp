#include <iostream>
using namespace std;

int bsearch(int a[], int n, int value) {
    int low = 0;
    int high = n-1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == value) {
            return mid;
        } else if (a[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int a[10] = {8, 11, 19, 23, 27, 33, 45, 55, 67, 98};
    int v;
    cin >> v;
    int ret = 0;
    ret = bsearch(a, 10, v);
    cout << ret << endl;
    return 0;
}