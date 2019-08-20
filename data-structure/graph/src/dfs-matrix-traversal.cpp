#include <iostream>
using namespace std;

const int kMaxV = 101;

typedef struct {
    int vetx[kMaxV]; // store weight
    int adj[kMaxV][kMaxV]; // adjacent matrix
    int vn; // vertex number
    int en; // edge number
} MGraph;

MGraph mg;
bool visited[kMaxV];

void Init() {
    // input vertex number, edge number
    cout << "input vertex number, edge number: ";
    cin >> mg.vn >> mg.en;

    // store vertex info
    cout << "input vertex info: ";
    for (int i = 1; i <= mg.vn; i++)
        cin >> mg.vetx[i];

    // store adjacent matrix info (from -> to -> w)
    cout << "input matrix info: ";
    for (int k = 1; k <= mg.en; k++) {
        int from, to, w;
        cin >> from >> to >> w;
        mg.adj[from][to] = w;
        mg.adj[to][from] = w;
    }
}

void PrintMatrix() {
    for (int i = 1; i <= mg.vn; i++) {
        for (int j = 1; j <= mg.vn; j++)
            cout << mg.adj[i][j] << " ";
        cout << endl;
    }
}

void DFS(int i) {
    cout << i << " "; // visit
    visited[i] = true; // mark

    for (int j = 1; j <= mg.vn; j++) {
        if (mg.adj[i][j] != 0 && !visited[j])
            DFS(j);
    }
}

void DFSTraversal() {
    memset(visited, false, sizeof(visited));

    cout << "DFS: ";
    for (int i = 1; i <= mg.vn; i++) {
        if (!visited[i])
            DFS(i);
    }
    cout << endl;
}

int main() {
    Init();
    PrintMatrix();
    DFSTraversal();

    return 0;
}
