#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n; // decimal number
    int d; // format
    cin >> n >> d;

    stack<int> out;
    do {
        out.push(n%d);
        n = n / d;
    } while (n != 0);

    while (!out.empty()) {
        cout << out.top();
        out.pop();
    }
    cout << endl;
    return 0;
}