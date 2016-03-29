#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

struct Union {
    vector<int> id;
    vector<int> s;
    Union(int n) {
        for (int i = 0; i < n; i++) {
            id.push_back(i);
            s.push_back(1);
        }
    }    
    int root(int v) {
        while (v != id[v])
            v = id[v];
        return id[v];
    }    
    bool isConnected(int v, int w) {
        return root(v) == root(w);
    }    
    void unite(int v, int w) {
        int i = root(v);
        int j = root(w);
        if (i == j)
            return;
        if (s[i] < s[j]) {
            id[i] = j;
            s[j] += s[i];
        }
        else {
            id[j] = i;
            s[i] += s[j];
        }
    }    
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M, x, y, r, s;
    cin >> N >> M;
    Union u(N);
    //vector<vector<Edge*> > g(N);
    
    auto comp = [](Edge* e1, Edge* e2) {return e1->weight > e2->weight;};
    priority_queue<Edge*, vector<Edge*>, decltype(comp)> pq(comp);    
    int tree_weight = 0;
    
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> r;
        Edge* e = new Edge(x, y, r);
        //g[x].push_back(e);
        pq.push(e);
    }
    cin >> s;
    
    while (!pq.empty()) {
        Edge* e = pq.top();
        pq.pop();
        int from = e->from;
        int to = e->to;
        //cout << from << " " << to << " " << e -> weight << endl;
        if (!u.isConnected(from, to)) {
            u.unite(from, to);
            tree_weight += e->weight;
        }
    }
    cout << tree_weight << endl;
    
    return 0;
}
