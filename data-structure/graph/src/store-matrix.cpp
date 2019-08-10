#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int adj[101][101];

    memset(adj, 0, sizeof(adj));

    // input vector, edge number
    int v, e;
    cin >> v >> e;

    int i, j, w;
    for (int k = 1; k <= e; k++) {
        cin >> i >> j >> w; // vector no. and weight
        adj[i][j] = w;
        adj[j][i] = w;
    }

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    return 0;
}