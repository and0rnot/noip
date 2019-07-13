#include <iostream>
using namespace std;

void h(int n, char a, char b, char c) {
    if (n == 1) {
        cout << "move one from tower " << a << " to tower " << c << endl;
        return;
    }

    h(n-1, a, c, b);
    h(1, a, b, c);
    h(n-1, b, a, c);
}

int main() {
    int plate_num;
    cin >> plate_num;
    h(plate_num, 'A', 'B', 'C');
    return 0;
}