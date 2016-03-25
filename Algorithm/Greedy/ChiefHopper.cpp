#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    long int x;
    vector<long int> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }
     
    // back track
    long int e = 0;
    for (int j = N - 1; j >= 0; j--) 
        e = (e + v[j]) % 2 == 0 ? (e + v[j]) / 2 : (e + v[j]) / 2 + 1; 
    
    cout << e << endl;
        
    return 0;
}
