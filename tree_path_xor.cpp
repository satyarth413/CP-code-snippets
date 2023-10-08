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
#define mod             1000000007
#define inf             100000000000000000 //1e17
#define Pi              acos(-1.0)
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
	//req variable
	int sum;
	//default value
	node()
	{
		sum = 0;
	}
};

int depth[101000], p[18][101000];

void build(int x, int pa, int d, vector<vector<int>> &adj) {
	depth[x] = d;
	p[0][x] = pa;
	for (int i = 1; i < 18; i++) {
		p[i][x] = p[i - 1][p[i - 1][x]];
	}
	for (int child : adj[x]) {
		if (child != pa) build(child, x, d + 1, adj);
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	int c = depth[a] - depth[b];
	for (int i = 0; i < 18; i++) {
		if ((c >> i) & 1) a = p[i][a];
	}
	if (a == b) return a;

	for (int i = 17; i >= 0; i--) {
		if (p[i][a] != p[i][b]) {
			a = p[i][a];
			b = p[i][b];
		}
	}
	return p[0][a];
}


class segte {
public:
	int n{};
	vector<node> tree;
	vector<int> a;
	node neutral;

	void init(int N) {
		n = N;
		tree.resize(4 * n + 1);
		//default values
		a.assign(n, 0);
	}

	void put(vector<int> &val) {
		a = val;
	}

	//merge function
	void merge(node &curr, node &left, node &right) {
		curr.sum = left.sum ^ right.sum;
	}

	//for leaf
	void single(node &curr, int idx) {
		curr.sum = a[idx];
	}

	void build(int index, int ss, int se) {
		if (ss == se) {
			single(tree[index], ss);
			return;
		}
		int mid = (ss + se) / 2;
		build(2 * index, ss, mid);
		build(2 * index + 1, mid + 1, se);
		merge(tree[index], tree[2 * index], tree[2 * index + 1]);
	}

	void build() {
		build(1, 0, n - 1);
	}

	node query(int index, int ss, int se, int qs, int qe) {
		if (qs > se || qe < ss) return neutral;
		if (qs <= ss && qe >= se) return tree[index];
		int mid = (ss + se) / 2;
		node left = query(2 * index, ss, mid, qs, qe);
		node right = query(2 * index + 1, mid + 1, se, qs, qe);
		node mer;
		merge(mer, left, right);
		return mer;
	}

	node query(int l, int r) {
		return query(1, 0, n - 1, l, r);
	}

	void update(int index, int idx, int ss, int se) {
		if (idx < ss || idx > se)
			return;
		if (ss == se) {
			single(tree[index], ss);
			return;
		}
		int mid = (ss + se) / 2;
		update(2 * index, idx, ss, mid);
		update(2 * index + 1, idx, mid + 1, se);
		merge(tree[index], tree[2 * index], tree[2 * index + 1]);
	}

	void update(int idx) {
		update(1, idx, 0, n - 1);
	}
};

const int mx = 1e5 + 200;
int st[mx], en[mx];
int timer = 0;
vector<int> tour;
vector<int> v;

void dfs(int s, int papa, vector<vector<int>> &adj) {
	tour[timer] = v[s];
	st[s] = timer++;
	for (int i : adj[s]) {
		if (i != papa) {
			dfs(i, s, adj);
		}
	}
	tour[timer] = v[s];
	en[s] = timer++;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("myinput.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
#endif
	FIO;
	int test_cases = 1;
	// cin >> test_cases;
	for (int tt = 1; tt <= test_cases; tt++)
	{
		int n, q;
		cin >> n >> q;
		tour.resize(2 * n, 0);
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		vector<vector<int>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(0, 0, adj);
		build(0, 0, 0, adj);
		segte mys;
		mys.init(2 * n);
		mys.put(tour);
		mys.build();
		while (q--)
		{
			int type;
			cin >> type;
			if (type == 1)
			{
				int s, x;
				cin >> s >> x;
				s--;
				mys.a[st[s]] = x;
				mys.a[en[s]] = x;
				mys.update(st[s]);
				mys.update(en[s]);
			}
			else
			{
				int s, e;
				cin >> s >> e;
				s--;
				e--;
				cout << (mys.query(0, st[s]).sum ^ mys.query(0, st[e]).sum ^ mys.a[st[lca(s, e)]] ) << endl;
			}
		}
	}
}