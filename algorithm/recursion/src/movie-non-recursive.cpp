#include <iostream>
using namespace std;

// formula: f(n) = f(n-1) + 1
int f(int n) {
    int a = 1;
    for (int i = 2; i <= n; i++)
        a = a + 1;

    return a;
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
}