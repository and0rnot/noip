#include <iostream>
#include <cstring>
using namespace std;

const int kMaxV = 101;
const int kBig = 50000;

typedef struct {
    int adj[kMaxV][kMaxV]; // adjacent matrix
    int dis[kMaxV][kMaxV]; // distance matrix
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
        }
    }

    for (int k = 1; k <= mg.vn; k++) {
        for (int i = 1; i <= mg.vn; i++) {
            for (int j = 1; j <= mg.vn; j++) {
                if (mg.dis[i][j] > mg.dis[i][k] + mg.dis[k][j]) {
                    mg.dis[i][j] = mg.dis[i][k] + mg.dis[k][j];
                }
            }
        }
    }
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

    return 0;
}
