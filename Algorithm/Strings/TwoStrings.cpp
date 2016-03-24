#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    string s1, s2;
    cin >> T;
    for (int i = 0; i < T; i++) {
        vector<int> v(26, -1);
        cin >> s1 >> s2;
        for (char c : s1)
            v[c - 'a'] = 1;
        
        bool isSubString = false;
        for (char x : s2) {
            if (v[x - 'a'] == 1){
               isSubString = true; 
                break;
            }
        }
        if (isSubString)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
