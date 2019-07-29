#include <iostream>
using namespace std;

int bsearch_recur(int a[], int low, int high, int value) {
    if (low > high)
        return -1;
    
    int mid = low + (high-low)/2;
    if (a[mid] == value)
        return mid;
    else if (a[mid] < value)
        return bsearch_recur(a, mid+1, high, value);
    else
        return bsearch_recur(a, low, mid-1, value);
}

int main() {
    int a[10] = {8, 11, 19, 23, 27, 33, 45, 55, 67, 98};
    int v;
    cin >> v;
    int ret = 0;
    ret = bsearch_recur(a, 0, 9, v);
    cout << ret << endl;
    return 0;
}