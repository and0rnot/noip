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
int path[kMaxV];

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

void DFS(int from, int to, int path[]) {
    visited[from] = true; // mark
    if (from == to)
        return;

    for (int j = 1; j <= mg.vn; j++) {
        if (mg.adj[from][j] != 0 && !visited[j]) {
            path[j] = from;
            DFS(j, to, path);
        }
    }
}

void DFSSearch(int from, int to) {
    memset(visited, false, sizeof(visited));
    memset(path, -1, sizeof(path));

    cout << "DFS[" << from <<"," << to << "]" << endl;
    for (int i = 1; i <= mg.vn; i++) {
        if (!visited[i])
            DFS(from, to, path);
    }
    cout << endl;
}

void PrintPath(int from, int to) {
    if (path[to] != -1 && from != to)
        PrintPath(from, path[to]);
    cout << to << " ";
}

int main() {
    Init();
    PrintMatrix();

    int from, to;
    cout << "from -> to: ";
    cin >> from >> to;
    DFSSearch(from, to);
    PrintPath(from, to);

    return 0;
}
