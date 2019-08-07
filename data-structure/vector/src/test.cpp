#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    cout << a.size() << endl;

    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.insert(a.begin()+1, 3);

    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;

    a.pop_back();
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
