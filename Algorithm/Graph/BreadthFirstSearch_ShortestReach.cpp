#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Use adjacency metrix

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, N, M, x, y, s, d;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        int dist[N + 1][N + 1];
        
        for (int j = 1; j < N + 1; j++) {
            for (int k = 1; k < N + 1; k++)
                dist[j][k] = 100;
        }
        
        for (int j = 0; j < M; j++) {
            cin >> x >> y;
            dist[x][y] = 6;
            dist[y][x] = 6;
        }
        
        cin >> s;
        
        // floyd algorithm, through l
        for (int l = 1; l < N + 1; l++) {
            for (int j = 1; j < N + 1; j++) {
                for (int k = 1; k < N + 1; k++) {
                    if (dist[j][l] + dist[l][k] < dist[j][k])
                        dist[j][k] = dist[j][l] + dist[l][k]; 
                }
            }                
        } 
        // print answer
        int tmp;
        for (int j = 1; j < N + 1; j++){
            if (j != s) {
                if (dist[s][j] == 100)
                    tmp = -1;
                else
                    tmp = dist[s][j];
                cout << tmp << " ";
            }
        }
        cout << endl;
        
    }
    return 0;
}
