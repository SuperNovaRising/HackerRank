#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M, x, y;
    vector<int> freq(10001, 0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        freq[x] -= 1;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> y;
        freq[y] += 1;
    }
    
    for (int i = 1; i < 10001; i++) {
        if (freq[i] > 0) 
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
