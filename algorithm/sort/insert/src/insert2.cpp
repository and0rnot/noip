#include <iostream>
using namespace std;

void InsertSort(int a[], int n) {
    if (n <= 1)
        return;
    
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        // find insert place from back
        for (; j >= 0; j--) {
            if (a[j] > key)
                a[j+1] = a[j]; // move
            else
                break;
            
        }
        // insert
        a[j+1] = key;
    }
}

void Print(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[8] = {3, 1, 7, 5, 2, 4, 9, 6};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Before: " << endl;
    Print(a, n);
    InsertSort(a, n);

    cout << "After: " << endl;
    Print(a, n);
    return 0;
}