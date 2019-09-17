#include <iostream>
#include <cstring>
using namespace std;

const int kMaxV = 101;
const int kBig = 50000;

typedef struct {
    int vetx[kMaxV]; // store vertex info
    int adj[kMaxV][kMaxV]; // adjacent matrix
    int dis[kMaxV][kMaxV]; // distance matrix
    int path[kMaxV][kMaxV]; // store path info
    int vn; // vertex number
    int en; // edge number
} FloyedGraph;

FloyedGraph mg;

void CreateGraph() {
    for (int i = 1; i <= kMaxV; i++)
        for (int j = 1; j <= kMaxV; j++)
            mg.adj[i][j] = kBig;

    // input vertex number, edge number
    cin >> mg.vn >> mg.en;

    // store vertex info
    for (int i = 1; i <= mg.vn; i++)
        cin >> mg.vetx[i];

    // store adjacent matrix info (from -> to -> w)
    for (int k = 1; k <= mg.en; k++) {
        int from, to, w;
        cin >> from >> to >> w;
        mg.adj[from][to] = w;
    }
}

void PrintMatrix() {
    // print matrix
    for (int i = 1; i <= mg.vn; i++) {
        for (int j = 1; j <= mg.vn; j++)
            cout << mg.adj[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void PrintDistance() {
    for (int i = 1; i <= mg.vn; i++) {
        for (int j = 1; j <= mg.vn; j++)
            cout << mg.dis[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void Floyed() {
    // init distance and path
    for (int i = 1; i <= mg.vn; i++) {
        for (int j = 1; j <= mg.vn; j++) {
            mg.dis[i][j] = mg.adj[i][j];

            if (mg.dis[i][j] != kBig)
                mg.path[i][j] = i;
            else
                mg.path[i][j] = 0;
        }
    }
    for (int k = 1; k <= mg.vn; k++) {
        for (int i = 1; i <= mg.vn; i++) {
            for (int j = 1; j <= mg.vn; j++) {
                if (mg.dis[i][j] > mg.dis[i][k] + mg.dis[k][j]) {
                    mg.dis[i][j] = mg.dis[i][k] + mg.dis[k][j];
                    mg.path[i][j] = k;
                }
            }
        }
    }
}

void PrintPath(int from, int to) {
    if (mg.path[from][to] != kBig && from != to)
        PrintPath(from, mg.path[from][to]);
    cout << to << " ";
}

int main() {

    CreateGraph();
    PrintMatrix();
    Floyed();
    PrintDistance();

    int from, to;
    cout << "input from - to: ";
    cin >> from >> to;
    cout << mg.dis[from][to] << endl;

    cout << "shortest path: ";
    PrintPath(from, to);

    return 0;
}
