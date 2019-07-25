#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef struct {
    string name;
    float score;
} StuSt;

bool comp_struct(StuSt a, StuSt b) {
    return (a.score < b.score? true: false);
}

int main() {
    StuSt a[10] = {
        {"lili", 32.8},
        {"mubai", 11.2},
        {"m2", 99.1},
    };

    sort(a, a+3, comp_struct);
    for (int i = 0; i < 3; i++) {
        cout << a[i].name << endl;
    }
    return 0;
}