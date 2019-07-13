#include <iostream>
using namespace std;

int store[10000];

int fib(int n) {
    if (n == 0 || n == 1)
        return n;
    
    if (store[n])
        return store[n];
    
    int ret = fib(n-1) + fib(n-2);
    store[n] = ret;
    return ret;
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
}