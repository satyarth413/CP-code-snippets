#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp; // 1 indexed
int edit_dist(string &a, string &b, int i, int j)
{
    if (!i) return j;
    if (!j) return i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i - 1] == b[j - 1])
        return dp[i][j] = edit_dist(a, b, i - 1, j - 1);
    else return dp[i][j] = 1 + min({
        edit_dist(a, b, i, j - 1), // inserting at b[j-1] after i-1 in a
        edit_dist(a, b, i - 1, j), // deleting a[i-1]
        edit_dist(a, b, i - 1, j - 1) // replacing a[i-1] by b[j-1]
    });
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string w1, w2;
    cin >> w1 >> w2;
    int n = w1.size();
    int m = w2.size();
    dp.resize(n + 1, vector<int>(m + 1, -1));

    int minCost = edit_dist(w1, w2, n, m);
    cout << minCost << endl;
}