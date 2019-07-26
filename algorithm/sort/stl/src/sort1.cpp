#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[10] = {133, 228, 1, 5 , 4, 0};
    // [fist, last) not include last
    sort(a, a+6);
    for (int i = 0; i < 6; i++)
        cout << a[i] << " ";
    cout << endl;
    
    float b[10] = {11.2, 0.8, 33.5, 1.3};
    sort(b, b+4);
    for (int i = 0; i < 4; i++)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}