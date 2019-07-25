#include <iostream>
#include <algorithm>
using namespace std;

bool int_asc(int a, int b) {
    return a < b ? true : false;
}

bool float_desc(float a, float b) {
    return a > b ? true : false;
}

int main() {
    int a[10] = {133, 228, 1, 5 , 4, 0};
    // [fist, last) not include last
    //sort(a, a+6, int_asc);
    sort(a, a+6, greater<int>());
    for (int i = 0; i < 6; i++)
        cout << a[i] << " ";
    cout << endl;
    
    float b[10] = {11.2, 0.8, 33.5, 1.3};
    //sort(b, b+4, float_desc);
    sort(b, b+4, less<float>());
    for (int i = 0; i < 4; i++)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}