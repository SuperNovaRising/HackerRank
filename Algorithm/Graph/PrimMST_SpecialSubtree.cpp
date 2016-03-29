#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge {
    int v1;
    int v2;
    int weight;
    Edge (int f, int t, int w) : v1(f), v2(t), weight(w) {}
    int other(int v) { return (v == v1) ? v2 : v1;}
};

auto comp = [](Edge* e1, Edge* e2) {return e1 -> weight > e2 -> weight;};
typedef priority_queue<Edge*, vector<Edge*>, decltype(comp)> EdgePQ;

void visit(vector<vector<Edge*> > &g, vector<int> &visited, EdgePQ &pq, int v) {
    visited[v] = 1;
    for (Edge *e : g[v]) {
        if (visited[e -> other(v)] == -1)
            pq.push(e);
    }
}

int main() {
    /* Enter your code here. Read input v1 STDIN. Print output v2 STDOUT */   
    int N, M, x, y, r, s;
    cin >> N >> M;
    vector<int> visited(N + 1, -1);
    vector<vector<Edge*> > g(N + 1);
    EdgePQ pq(comp);
    int tree_weight = 0;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> r;
        Edge* e = new Edge(x, y, r);    
        g[x].push_back(e);
        g[y].push_back(e);
    }
    cin >> s;
    visit(g, visited, pq, s);
    
    while (!pq.empty()) {
        Edge *e = pq.top();
        pq.pop();
        int v1 = e -> v1;
        int v2 = e -> v2;
        if(visited[v1] == 1 && visited[v2] == 1)
            continue;
        //cout << v1 << " " << v2 << " " << e -> weight << endl;
        tree_weight += e -> weight;
        if (visited[v1] == -1) {
            visit(g, visited, pq, v1);
        }    
        if (visited[v2] == -1) {
            visit(g, visited, pq, v2);
        }
    }
    cout << tree_weight << endl;
    
    return 0;
}
