#include <iostream>
using namespace std;

// formula: f(n) = f(n-1) + f(n-2)
int fib(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;

    int ret;
    int pre = 1;
    int ppre = 1;
    for (int i = 3; i <= n; i++) {
        ret = pre + ppre;
        ppre = pre;
        pre = ret;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}