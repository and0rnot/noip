#include <iostream>
using namespace std;

const int kMaxV = 101;

typedef struct AdjNode {
    int adjvex; // store adj vertex value
    int w; // store weight
    struct AdjNode* next;
} AdjNode;

typedef struct {
    int data; // vertex value
    AdjNode* first; // point to first adjacent vertex
} VNode;

typedef struct {
    VNode vetx[kMaxV]; // store vertex info
    int vn; // vertex number
    int en; // edge number
} ListGraph;

ListGraph lg;

int main() {
    // input vertex number, edge number
    cin >> lg.vn >> lg.en;
    
    // store vertex info
    for (int i = 1; i <= lg.vn; i++) {
        cin >> lg.vetx[i].data;
        lg.vetx[i].first = NULL;
    }

    // store adjacent list info (from -> to -> w)
    for (int k = 1; k <= lg.en; k++) {
        int from, to, w;
        cin >> from >> to >> w;
        
        AdjNode* an = new AdjNode;
        an->adjvex = to;
        an->w = w;
        an->next = lg.vetx[from].first;
        lg.vetx[from].first = an;
    }
    
    // print adjacent list
    for (int i = 1; i <= lg.vn; i++) {
        AdjNode* p = lg.vetx[i].first;
        while (p) {
            cout << "<" << lg.vetx[i].data << ", " << p->adjvex << ">" << p->w << " ";
            p = p->next;
        }
        cout << endl;
    }
    
    return 0;
}
