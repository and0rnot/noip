#include <iostream>
#include <cstring>
using namespace std;

const int kMaxV = 101;
const int kBig = 50000;

typedef struct {
    int adj[kMaxV][kMaxV]; // adjacent matrix
    int dis[kMaxV]; // distance matrix
    int book[kMaxV]; // store P,Q info
    int path[kMaxV]; // store path info
    int vn; // vertex number
    int en; // edge number
} DijkstraGraph;

DijkstraGraph dg;

void CreateGraph() {
    for (int i = 1; i <= kMaxV; i++)
        for (int j = 1; j <= kMaxV; j++)
            dg.adj[i][j] = kBig;

    // input vertex number, edge number
    cin >> dg.vn >> dg.en;

    memset(dg.path, -1, sizeof(dg.path));

    // store adjacent matrix info (from -> to -> w)
    for (int k = 1; k <= dg.en; k++) {
        int from, to, w;
        cin >> from >> to >> w;
        dg.adj[from][to] = w;
        dg.path[to] = from;
    }
}

void PrintMatrix() {
    // print matrix
    for (int i = 1; i <= dg.vn; i++) {
        for (int j = 1; j <= dg.vn; j++)
            cout << dg.adj[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void PrintDistance() {
    for (int j = 1; j <= dg.vn; j++)
        cout << dg.dis[j] << " ";
    cout << endl;
}

void Dijkstra(int x) {

    // init distance and book
    for (int j = 1; j <= dg.vn; j++) {
        dg.dis[j] = dg.adj[x][j];
        if (j == x) {
            dg.dis[j] = 0;
        }
        dg.book[j] = 0;
    }

    // init book
    dg.book[x] = 1;

    int u = x; // store the closest vertex

    // core
    for (int i = 1; i <= dg.vn-1; i++) { // x is put to P before the loop
        // find the closest vertex
        int min = kBig;
        for (int j = 1; j <= dg.vn; j++) {
            if (dg.book[j] == 0 && dg.dis[j] < min) {
                min = dg.dis[j];
                u = j;
            }
        }

        dg.book[u] = 1; // put u to P set

        for (int v = 1; v <= dg.vn; v++) {
            if (dg.adj[u][v] == kBig)
                continue;
            if (dg.dis[v] > dg.dis[u] + dg.adj[u][v]) {
                dg.dis[v] = dg.dis[u] + dg.adj[u][v];
                dg.path[v] = u;
            }
        }
    }
}

void PrintPath(int from, int to) {
    if (from != to && dg.path[to] != -1)
        PrintPath(from, dg.path[to]);

    if (dg.path[to] != -1)
        cout << to << " ";
}

int main() {

    CreateGraph();
    PrintMatrix();

    int from, to;
    cout << "from->to: ";
    cin >> from >> to;

    Dijkstra(from);
    PrintDistance();

    PrintPath(from, to);

    return 0;
}
