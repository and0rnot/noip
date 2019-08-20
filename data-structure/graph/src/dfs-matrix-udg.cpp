#include <iostream>
#include <cstring>
using namespace std;

const int kMax = 101;
int vex[kMax];
int adj[kMax][kMax];
int v, e;

void DFS_rec(int i, bool* visited) {
    visited[i] = true;

    cout << vex[i] << " ";
    for (int j = 1; j <= v; j++) {
        if (i != j && adj[i][j] == 1) {
            if (!visited[j])
                DFS_rec(j, visited);
        }
    }
}

void DFS() {
    bool visited[kMax]; // vertex visited flag

    memset(visited, false, sizeof(visited));
    cout << "DFS: ";

    for (int i = 1; i <= v; i++) {
        if (!visited[i])
            DFS_rec(i, visited);
    }

    cout << endl;
}

int main() {
    memset(adj, 0, sizeof(adj));

    // input vector, edge number
    cin >> v >> e;

    for (int i = 1; i <= v; i++)
        cin >> vex[i];

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

    DFS();

    return 0;
}