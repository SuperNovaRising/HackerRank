#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M, Q, x, y, r, a, b;
    long long int MAX_DIST = 1000000000;
    cin >> N >> M;
    long long int g[N + 1][N + 1];
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = MAX_DIST;
        }
    }
    
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> r;
        g[x][y] = r;        
    }
    
    for (int k = 1; k < N + 1; k++) {
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                if(g[i][k] + g[k][j] < g[i][j])
                    g[i][j] = g[i][k] + g[k][j]; 
            }
        }
    }
    
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        if (g[a][b] == MAX_DIST)
            cout << -1 << endl;
        else
            cout << g[a][b] << endl;
    }
    
    return 0;
}
