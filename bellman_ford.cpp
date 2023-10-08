#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define endl            "\n"
#define int             long long
#define pb              push_back
#define pii             pair<int,int>
#define setbits(x)      __builtin_popcountll(x)
#define zerbefone(x)    __builtin_ctzll(x)
#define pqb             priority_queue<int> // maxheap
#define pqs             priority_queue<int,vector<int>,greater<int> > // minheap
#define setbits(x)      __builtin_popcountll(x)
#define zerbefone(x)    __builtin_ctzll(x)
#define mod             1000000007
#define inf             100000000000000000 //1e17
#define Pi              acos(-1.0)
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<vector<int>> adj;

vector<int> bf()
{
	vector<int> dist(n);
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int u = adj[j][0];
			int v = adj[j][1];
			int w = adj[j][2];
			if (i <= n - 1)
				dist[v] = min(dist[v], dist[u] + w);
			else
			{
				if (dist[v] > dist[u] + w)
					dist[v] = -inf;
			}
		}
	}
	return dist;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("myinput.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
#endif
	FIO;
	int tt = 1;
	cin >> tt;
	while (tt--)
	{
		// Solution for codechef BEST PATHS PROBLEM
		cin >> n >> m;
		adj.clear();
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			u--;
			v--;
			adj.push_back({u, v, w});
		}
		vector<int> end = bf();
		for (auto v : adj)
			swap(v[0], v[1]);
		vector<int> start = bf();
		for (int i = 0; i < n; i++)
		{
			if (end[i] == -inf || start[i] == -inf)
				cout << "INF" << endl;
			else cout << (start[i] + end[i]) << endl;
		}
	}
	return 0;
}
