#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, K, unfairness = INT_MAX, x;
    cin >> N >> K;
    vector<int> list;
    for (int i=0; i<N; i++) {
        cin >> x;
        list.push_back(x);
    }
    sort(list.begin(), list.end());
    for (int i = 0; i < N - K + 1; i++) {
        if (list[i + K - 1] - list[i] < unfairness)
            unfairness = list[i + K - 1] - list[i];
        if (unfairness == 0)
            break;
    }
    
    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    cout << unfairness << "\n";
    return 0;
}
