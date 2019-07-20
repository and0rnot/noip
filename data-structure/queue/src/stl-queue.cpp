#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    queue<string> qc;

    int n;
    int x = 0;
    while (cin >> n) {
        if (n == 9)
            break;

        if (n == 1) {
            x++;
            string s = "color" + to_string(x);
            qc.push(s);
        }

        if (n == 2) {
            if (!qc.empty()) {
                cout << qc.front() << endl;
                qc.pop();
            } else {
                cout << "dequeue err" << endl;
            }
        }
    }
    return 0;
}