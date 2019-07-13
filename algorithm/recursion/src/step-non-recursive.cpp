#include <iostream>
using namespace std;

// formula: f(n) = f(n-1) + f(n-2)
int f(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int ret; // store f(n)
    int pre = 2; // store f(n-1)
    int ppre = 1; // store f(n-2)
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
    cout << f(n) << endl;
    return 0;
}