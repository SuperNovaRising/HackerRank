/* Sample program illustrating input/output */
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
//Helpers for input and output

    int N, K, x;
    cin >> N >> K;
    vector<int> C(N);
    for(int i = 0; i < N; i++){
        cin >> x;
        C.push_back(x);
    }
    sort(C.rbegin(), C.rend());
   
    int result = 0;
    for (int i = 0; i < N; i++) {
        result += (i / K + 1) * C[i];
    }
        
        
    cout << result << "\n";
   
    return 0;
}
