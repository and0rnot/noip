#include <iostream>
using namespace std;

const int kMaxV = 101;

typedef struct {
    int adj[kMaxV][kMaxV];
    int vd[kMaxV]; // vertex degree
    int vn;
    int en;
} MGraph;

typedef struct {
    int path[kMaxV];
    int n;
} EulerPath;

MGraph mg;
EulerPath ep;

void FindEulerPath(int from) {
    for (int to = 1; to <= mg.vn; to++) {
        if (mg.adj[from][to] == 1) {
            // remove the edge, in case go again
            mg.adj[from][to] = 0;
            mg.adj[to][from] = 0;
            FindEulerPath(to);
        }
    }

    ep.path[++ep.n] = from;
}

int main() {
    cout << "input vertex number, edge number: ";
    cin >> mg.vn >> mg.en;

    cout << "matrix info: " << endl;
    for (int i = 1; i <= mg.en; i++) {
        int from, to;
        cin >> from >> to;
        mg.adj[from][to] = 1;
        mg.adj[to][from] = 1;
        mg.vd[from]++;
        mg.vd[to]++;
    }

    int start = 1;
    // find odd vertex
    for (int i = 1; i <= mg.vn; i++) {
        if (mg.vd[i] % 2 == 1) {
            start = i;
            break;
        }
    }

    cout << "start: " << start << endl;
    FindEulerPath(start);

    for (int i = ep.n; i >= 1; i--)
        cout << ep.path[i] << " ";
    cout << endl;


    return 0;
}
