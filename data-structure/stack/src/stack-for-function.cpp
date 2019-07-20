#include <iostream>
using namespace std;

int add(int a, int b) {
    int sum = 0;
    sum = a + b;
    return sum;
}

int main() {
    int ret = 0;
    ret = add(3, 5);
    cout << ret << endl;
    return 0;
}
