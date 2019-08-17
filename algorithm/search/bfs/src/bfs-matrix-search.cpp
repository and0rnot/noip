#include <iostream>
#include <queue>
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
queue<int> q;
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

void BFSSearch(int from, int to) {
    memset(visited, false, sizeof(visited));

    cout << "BFS[" << from <<"," << to << "]" << endl;
    for (int i = 1; i <= mg.vn; i++) {
        if (visited[i])
            continue;

        visited[i] = true;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int j = 1; j <= mg.vn; j++) {
                if (mg.adj[v][j] != 0 && !visited[j]) {
                    path[j] = v;
                    visited[j] = true;
                    if (v == to)
                        return;

                    q.push(j);
                }
            }
        }
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
    BFSSearch(from, to);
    PrintPath(from, to);
    cout << endl;

    return 0;
}
