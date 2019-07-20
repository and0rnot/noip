#include <iostream>
#include <string>
using namespace std;

const int kMax = 7;

typedef struct {
    string colors[kMax];
    int top;
} ColorStackSt;

ColorStackSt cs;

static bool push(string color) {
    // check if full
    if (cs.top >= kMax)
        return false;
    cs.top++;
    cs.colors[cs.top] = color;
    return true;
}

static bool pop() {
    // check empty
    if (cs.top <= 0)
        return false;

    cs.top--;
    return true;
}

static string top() {
    if (cs.top > 0 && cs.top < kMax)
        return cs.colors[cs.top];
    return "";
}

static bool empty() {
    if (cs.top <= 0)
        return true;
    else
        return false;
}

int main() {
    string color;
    while (cin >> color) {
        if (color == "q")
            break;
        push(color);
    }
    
    while (!empty()) {
        cout << top() << endl;
        pop();
    }
    return 0;
}