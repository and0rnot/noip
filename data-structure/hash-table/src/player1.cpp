#include <iostream>
#include <string>
using namespace std;

int player_hash(int key) {
    return key;
}

int main() {
    string players[6] = { "", "a1", "a2", "a3", "a4", "a5" };
    int n;
    cin >> n;
    if (n >= 1 && n <= 5) {
        int kv = player_hash(n);
        cout << players[kv] << endl;
    }
    return 0;
}
