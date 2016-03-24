#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(vector<int> &path) {
    for (int c : path)
        cout << c << " ";
    cout << endl;
}

void DFS(vector<vector<int> > &g, vector<int> &visited, int id, const int end, bool &to_end, vector<int> &path) {
    if (visited[id] == 1)
        return;
    if (to_end)
        return;
    if (id == end) 
        to_end = true;
    
    visited[id] = 1;
    path.push_back(id);
    
    
    vector<int>::iterator it;
    for (it = g[id].begin(); it != g[id].end(); it++) {
        if (visited[*it] != 1)
            DFS(g, visited, *it, end, to_end, path);
    }
    if (!to_end)
        path.pop_back();
    //cout << id << ": ";
    //print(path);
}


void buildGraph(vector<vector<char> > &v, vector<vector<int> > &g, int i, int j) {
    if (v[i][j] == 'X')
        return;
    int M = v.size();
    int N = v[0].size();
    int p = i * N + j;
    
    int k = i;
    for (int l = j - 1; l < j + 1; l++) {
        if (k < 0 || l < 0 || k >= M || l >= N || v[k][l] == 'X')
            continue;
        if (i == k && j == l) 
            continue;
        int q = k * N + l;
        g[p].push_back(q); g[q].push_back(p);
    }
    int l = j;
    for (int k = i - 1; k < i + 1; k++) {
        if (k < 0 || l < 0 || k >= M || l >= N || v[k][l] == 'X')
            continue;
        if (i == k && j == l) 
            continue;
        int q = k * N + l;
        g[p].push_back(q); g[q].push_back(p);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, N, M, start, end, bet, count;
    char x;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> N;
        vector<vector<char> > v(M);
        vector<int> visited(M * N, -1);
        vector<vector<int> > g(M * N);
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                cin >> x;
                if (x == 'M')
                    start = j * N + k;
                if (x == '*')
                    end = j * N + k;
                v[j].push_back(x);
            }
        }
        cin >> bet;
        
        for (int j = 0; j < M; j++) 
            for (int k = 0; k < N; k++) 
                buildGraph(v, g, j, k);
            
        // DFS
        vector<int> path;
        bool to_end = false;
        int count = 0;
        DFS(g, visited, start, end, to_end, path);
        for (int c : path) {
            if (c == end)
                continue;
            if ((c == start && g[c].size() >= 2) || (c != start && g[c].size() >= 3))
                count++;
        }
        //cout << count << endl;
        
        if (count == bet)
            cout << "Impressed" << endl;
        else
            cout << "Oops!" << endl;
    }
    return 0;
}
