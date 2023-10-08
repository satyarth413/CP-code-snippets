// Code in regards to problem:
// https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-2/problems/B?source=codeforces

const int MAX_N = 800005;

int bridgec;
vector<int> adj[MAX_N];
int lvl[MAX_N];
int dp[MAX_N];
vector<array<int, 2>> bridges;

void dfs (int vertex, int par = -1) {
	dp[vertex] = 0;
	for (int nxt : adj[vertex]) {
		if (lvl[nxt] == 0) { /* edge to child */
			lvl[nxt] = lvl[vertex] + 1;
			dfs(nxt, vertex);
			dp[vertex] += dp[nxt];
		} else if (lvl[nxt] < lvl[vertex]) { /* edge upwards */
			dp[vertex]++;
		} else if (lvl[nxt] > lvl[vertex]) { /* edge downwards */
			dp[vertex]--;
		}
	}

	/* the parent edge isn't a back-edge, subtract 1 to compensate */
	dp[vertex]--;

	if (lvl[vertex] > 1 && dp[vertex] == 0) {
		bridgec++;
		bridges.push_back({vertex, par});
	}
}

void solve() {
	int n;
	cin >> n;
	bridgec = 0;
	bridges.clear();
	forn(i, n + 1)
	{
		adj[i].clear();
		dp[i] = 0;
		lvl[i] = 0;
	}
	forn(i, n - 1) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int> freq(n);
	forn(i, n) cin >> freq[i];
	vector<vector<int>> temp(n);
	forn(i, n) {
		temp[freq[i] - 1].push_back(i + 1);
	}
	forn(i, n) {
		int m = sz(temp[i]);
		if (m >= 2) {
			forn(j, m - 1) {
				adj[temp[i][j]].push_back(temp[i][j + 1]);
				adj[temp[i][j + 1]].push_back(temp[i][j]);
			}
			adj[temp[i][m - 1]].push_back(temp[i][0]);
			adj[temp[i][0]].push_back(temp[i][m - 1]);
		}
	}
	lvl[1] = 1;
	dfs(1);
	cout << bridgec << endl;
	// for(auto p:edges)
	// 	cout<<p.ff+1<<" "<<p.ss+1<<endl;
	// auto bridges=find_bridges(adj,n,sz(edges));
	// cout << sz(bridges) << endl;
	// for(auto [u,v]:bridges)
	// 	cout<<u<<" "<<v<<endl;
}