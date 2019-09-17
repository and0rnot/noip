#include <iostream>
using namespace std;

const int kMax = 101;
int roots[kMax];

void MakeSet(int num) {
    for (int i = 1; i <= num; i++)
        roots[i] = i; // I'm the boss
}

int FindRoot(int x) {
    if (x == roots[x])
        return x;
    return FindRoot(roots[x]);

    roots[x] = FindRoot(roots[x]);
    return roots[x];
}

void Union(int x, int y) {
    int xr = FindRoot(x);
    int yr = FindRoot(y);
    // make right set as left set's child set
    roots[yr] = xr;
}

bool IsSameSet(int x, int y) {
    return FindRoot(x) == FindRoot(y);
}

int main() {
    int n, m;
    cin >> n >> m;

    MakeSet(n);

    // merge gangs
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }

    // check independent gangs number
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == roots[i])
            ans++;
    }
    cout << ans << endl;
}