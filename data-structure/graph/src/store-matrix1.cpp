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

int main() {
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
        mg.adj[to][from] = w;
    }

    // print matrix
    for (int i = 1; i <= mg.vn; i++) {
        for (int j = 1; j <= mg.vn; j++)
            cout << mg.adj[i][j] << " ";
        cout << endl;
    }
    return 0;
}
