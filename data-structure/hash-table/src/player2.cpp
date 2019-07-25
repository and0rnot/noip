#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int player_hash(string key) {
    // get last two char
    string last_two_char = key.substr(key.size()-2);
    // convert to int
    //int kv = stoi(last_two_char);
    int kv = atoi(last_two_char.c_str());
    return kv;
}

int main() {
    string players[6] = { "", "a1", "a2", "a3", "a4", "a5" };
    string key;
    cin >> key;
    int kv = player_hash(key);
    cout << players[kv] << endl;
    return 0;
}