#include <iostream>
#include <cstring>
using namespace std;

const int kMaxV = 20;

typedef struct ArcNode {
    int adjvex; // store adjacent vertex pos in array
    struct ArcNode* nextarc;
    int w;
} ArcNode;

typedef struct VNode {
    int data; // vertex data
    ArcNode* firstarc;
} VNode, AdjList[kMaxV]; // use array to store link head

typedef struct {
    AdjList vertexs; // vertex array
    int vn; // vertex number
    int en; // edge number
} ALGraph;

void Create(ALGraph* g) {
    cout << "input vertex number, edge number: ";
    // input vertex number & edge number
    cin >> g->vn >> g->en;

    // input vertex info
    cout << "\ninput vertex info: " << endl;
    for (int i = 1; i <= g->vn; i++) {
        cin >> g->vertexs[i].data;
        g->vertexs[i].firstarc = NULL;
    }

    // create adjacent list
    cout << "\ninput edge info:" << endl;
    for (int k = 1; k <= g->en; k++) {
        int from, to, w;
        cin >> from >> to >> w;

        ArcNode* an = new ArcNode;
        an->adjvex = to; // adjacent vertex pos
        an->w = w;
        an->nextarc = g->vertexs[from].firstarc;
        g->vertexs[from].firstarc = an;
    }
}

void Show(ALGraph* g) {
    for (int i = 1; i <= g->vn; i++) {
        ArcNode* p = g->vertexs[i].firstarc;
        while (p) {
            cout << "<" << g->vertexs[i].data << ", " << p->adjvex << ">" << "(" << p->w << ")" << " ";
            p = p->nextarc;
        }
        cout << endl;
    }
}

void DFS_rec(ALGraph* g, int i, bool* visited) {
    visited[i] = true;

    cout << g->vertexs[i].data << " ";
    ArcNode* p = g->vertexs[i].firstarc;
    while (p) {
        if (!visited[p->adjvex])
            DFS_rec(g, p->adjvex, visited);
        p = p->nextarc;
    }
}

void DFS(ALGraph* g) {
    bool visited[kMaxV]; // vertex visited flag

    memset(visited, false, sizeof(visited));
    cout << "DFS: ";

    for (int i = 1; i <= g->vn; i++) {
        if (!visited[i])
            DFS_rec(g, i, visited);
    }

    cout << endl;
}

int main() {
    ALGraph g;
    Create(&g);
    Show(&g);
    DFS(&g);

    return 0;
}
