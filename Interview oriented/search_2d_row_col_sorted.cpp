#include "bits/stdc++.h"
using namespace std;

int main() {
    int m, n, k;
    cout << "what is the value of m and n and k" << endl;
    cin >> m >> n >> k;
    int a[m][n];
    for (int i = 0 ; i < m ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    int r = 0 , c = n - 1 ;
    while (r < m && c >= 0 ) {
        if (a[r][c] == k) {
            ans = 1;
        }
        else if (a[r][c] > k) {
            c--;
        }
        else {
            r++;
        }
    }
    if (ans ==  0) {
        cout << "Element not found" << endl;
    }
    else {
        cout << "Element found" << endl;
    }
    return 0;
}