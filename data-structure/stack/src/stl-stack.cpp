#include <iostream>
#include <string>
#include <stack> // for stack<T> container

using namespace std;

int main() {
    stack<string> colors;

    string color;
    while (cin >> color) {
        if (color == "q")
            break;
        colors.push(color);
    }

    cout << colors.size() << endl;
    cout << "current top: " << colors.top() << endl;

    while (!colors.empty()) {
        string c = colors.top();
        cout << c << endl;
        colors.pop();
    }
    
    return 0;
}