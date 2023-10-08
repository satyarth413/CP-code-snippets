const int N = 2e5;
int cost[N + 1], sum[N + 1], a[N + 1];
vector<int> adj[N + 1];
int ans = 0;

void preCal(int u = 1, int prev = 0)
{
    sum[u] = a[u];
    for (auto v : adj[u])
    {
        if (v == prev) continue;
        preCal(v, u);
        sum[u] += sum[v];
        cost[u] += sum[v] + cost[v];
    }
}

void dfs(int u = 1, int prev = 0)
{
    ans = max(ans, cost[u]);
    for (auto v : adj[u])
    {
        if (v == prev) continue;
        int newCost = cost[u] - cost[v] - sum[v];
        cost[v] += newCost + sum[u] - sum[v];
        sum[v] = sum[u];
        dfs(v, u);
    }
}

void solve(int tc)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    preCal();
    dfs();

    print(ans);
}