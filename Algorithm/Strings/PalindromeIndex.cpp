#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    string s;
    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> s;
        int j = 0, k = s.size() - 1;
        while (j < k) {
           if (s[j] != s[k]) {
               if (s[j + 1] == s[k] && s[j + 2] == s[k - 1]) {
                   cout << j << endl;
                   break;
               }
               else if (s[j] == s[k - 1] && s[j + 1] == s[k - 2]) {
                   cout << k << endl;
                   break;
               }
           }
           else 
               j++; k--;
        }
        if (j >= k)
            cout << -1 << endl;
    }
    return 0;
}
