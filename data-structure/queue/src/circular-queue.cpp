#include <iostream>
#include <string>
using namespace std;

const int kMax = 7;

struct Que {
    string color[kMax];
    int head;
    int tail;
};

Que q;

bool enqueue(string c) {
    // check full
    if ((q.tail + 1)%kMax == q.head)
        return false;

    q.color[q.tail] = c;
    q.tail = (q.tail + 1) % kMax;
    return true;
}

string dequeue() {
    if (q.head == q.tail)
        return "";
    string ret = q.color[q.head];
    q.head = (q.head + 1) % kMax;
    return ret;
}

int main() {
    int n;
    int x = 0;
    while (cin >> n) {
        if (n == 9)
            break;

        if (n == 1) {
            x++;
            string s = "color" + to_string(x);
            if (enqueue(s) == false)
                cout << "enqueue err" << endl;
        }

        if (n == 2) {
            string out = dequeue();
            if (out == "")
                cout << "dequeue err" << endl;
            else
                cout << out << endl;
        }
    }
    return 0;
}