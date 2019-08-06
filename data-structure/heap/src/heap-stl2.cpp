#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void show(vector<int>& a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    vector<int> v;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;
        v.push_back(value);
    }

    make_heap(v.begin(), v.end());
    show(v);

    int a;
    cin >> a;
    v.push_back(a); // add to tail
    push_heap(v.begin(), v.end());
    show(v);

    pop_heap(v.begin(), v.end());
    v.pop_back(); // remove tail
    show(v);

    return 0;
}