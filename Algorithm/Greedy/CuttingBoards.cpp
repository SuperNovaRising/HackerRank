#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, N, M;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        vector<long long int> cy(N - 1);
        vector<long long int> cx(M - 1);
        int x_seg = 1, y_seg = 1;
        for (int j = 0; j < N - 1; j++)
            cin >> cy[j];
        for (int j = 0; j < M - 1; j++)
            cin >> cx[j];
        
        sort(cx.begin(), cx.end(), &comp);
        sort(cy.begin(), cy.end(), &comp);
        
        
        int j = 0, k = 0;
        long long cost = 0;
        while (j < N - 1 && k < M - 1) {
            if (cy[j] > cx[k]) {
                cost += cy[j++] * x_seg; y_seg++;
            }
            else { 
                cost += cx[k++] * y_seg; x_seg++;
            }
        }
        while (j < N - 1) {
            cost += cy[j++] * x_seg; y_seg++;
        }
        while (k < M - 1) {
            cost += cx[k++] * y_seg; x_seg++;
        }
        cout << cost % static_cast<long long>(pow(10, 9) + 7) << endl;
        
    }
    return 0;
}
