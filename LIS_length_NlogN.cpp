vector<int> last(N + 1);
int inf = 1e8;
for (int i = 1; i <= N; i++)
    last[i] = inf;
last[0] = -inf;
for (int i = 1; i <= N; i++) {
    int idx = lower_bound(last.begin(), last.end(), H[i - 1])-last.begin();
    last[idx] = H[i-1];
}
int lis_len = 0;
for (int i = 1; i <= N; i++)
    if (last[i] != inf)
        lis_len = i;