#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M, a, b, k;
    unsigned long long x = 0, max = 0;
    cin >> N >> M;
    vector<unsigned long long> v(N + 1, 0);
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> k;
        v[a] += k;
        if (b + 1 <= N)
            v[b + 1] -= k;
    }
    
    for (int i = 1; i < N + 1; i++) {
        x += v[i];
        if (x > max)
            max = x; 
    }
    cout << max << endl;
    return 0;
}
