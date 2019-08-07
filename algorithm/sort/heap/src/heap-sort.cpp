#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void heap_sort(int a[], int n) {
    make_heap(a+1, a+n+1);
    int k = n;
    while (k > 1) {
        swap(a[1], a[k]);
        k--;
        make_heap(a+1, a+k+1);
    }
}

int main() {
    int a[1000] = {0};
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    heap_sort(a, n);

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}