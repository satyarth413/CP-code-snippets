// SPACE 2*M : actually you can take minimum of both string's length(swap) and then, SPACE= O(N+M)
int minDistMinMemory(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> curr(2, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                curr[i & 1][j] = i + j;
            else if (word1[i - 1] == word2[j - 1])
                curr[i & 1][j] = curr[i & 1 ^ 1][j - 1];
            else curr[i & 1][j] = 1 + min({
                curr[i & 1][j - 1], // inserting word2[j-1] after i-1 in word1
                curr[i & 1 ^ 1][j], // deleting word1[i-1]
                curr[i & 1 ^ 1][j - 1] // replacing word1[i-1] by word2[j-1]
            });
        }
    }
    return curr[n & 1][m];
}

// SPACE : N*M

int minDistanceMoreMemory(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    int dp[n + 1][m + 1]; // 1 indexed
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = i + j; // if i=0 then j deletions and vice versa
            else if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min({
                dp[i][j - 1], // inserting word2[j-1] after i-1 in word1
                dp[i - 1][j], // deleting word1[i-1]
                dp[i - 1][j - 1] // replacing word1[i-1] by word2[j-1]
            });
        }
    }
    return dp[n][m];
}

