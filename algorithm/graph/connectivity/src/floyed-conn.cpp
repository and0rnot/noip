#include <iostream>
#include <cstring>
using namespace std;

const int kMaxV = 101;

typedef struct {
    int adj[kMaxV][kMaxV]; // adjacent matrix
    int dis[kMaxV][kMaxV]; // distance matrix
    int vn; // vertex number
    int en; // edge number
} FloyedGraph;

FloyedGraph fg;

void CreateGraph() {
    for (int i = 1; i <= kMaxV; i++)
        for (int j = 1; j <= kMaxV; j++)
            fg.adj[i][j] = false;

    // input vertex number, edge number
    cin >> fg.vn >> fg.en;

    // store adjacent matrix info (from -> to -> w)
    for (int k = 1; k <= fg.en; k++) {
        int from, to, w;
        cin >> from >> to >> w;
        fg.adj[from][to] = true;
    }
}

void PrintMatrix() {
    // print matrix
    for (int i = 1; i <= fg.vn; i++) {
        for (int j = 1; j <= fg.vn; j++)
            cout << fg.adj[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void PrintConnectivity() {
    for (int i = 1; i <= fg.vn; i++) {
        for (int j = 1; j <= fg.vn; j++)
            cout << fg.dis[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void Floyed() {
    // init distance and path
    for (int i = 1; i <= fg.vn; i++) {
        for (int j = 1; j <= fg.vn; j++) {
            fg.dis[i][j] = fg.adj[i][j];
        }
    }

    for (int k = 1; k <= fg.vn; k++) {
        for (int i = 1; i <= fg.vn; i++) {
            for (int j = 1; j <= fg.vn; j++) {
                fg.dis[i][j] = fg.dis[i][j] || (fg.dis[i][k] && fg.dis[k][j]);
            }
        }
    }
}

int main() {

    CreateGraph();
    PrintMatrix();
    Floyed();
    PrintConnectivity();

    int from, to;
    cout << "input from - to: ";
    cin >> from >> to;
    cout << fg.dis[from][to] << endl;

    return 0;
}
