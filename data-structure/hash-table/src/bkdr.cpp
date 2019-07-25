#include <iostream>
#include <string>
using namespace std;

unsigned int bkdr_hash(string s) {
    unsigned int seed = 131;
    unsigned int hash = 0;

    for (int i = 0; i < s.size(); i++) {
        hash = hash*seed + s[i];
    }
    return hash & 0x7fffffff; // [0, MAX)
}

int main() {
    string s;
    cin >> s;
    cout << bkdr_hash(s) << endl;
    return 0;
}