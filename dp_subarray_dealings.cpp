#include<bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

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
// #define oset            tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

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
		int n;
		cin >> n;
		vector<int> v(n + 1);
		int dp[n + 1][n + 1];
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
			dp[1][i] = v[i];
		}
		for (int len = 2; len <= n; len++)
		{
			for (int j = 1; j <= n - 1; j++)
			{
				dp[len][j] = dp[len - 1][j] ^ dp[len - 1][j + 1];
			}
		}

		// dp[i][j] has answer for length i and starting j
		// below nested loop calculated dp[i][j] as maximum answer for all subsegments/subarrays within i...j
		for (int len = 2; len <= n; len++)
		{
			for (int j = 1; j <= n - 1; j++)
			{
				dp[len][j] = max(dp[len][j], max(dp[len - 1][j], dp[len - 1][j]));
			}
		}
		int q;
		cin >> q;
		while (q--)
		{
			int l, r;
			cin >> l >> r;
			cout << dp[r - l][l] << endl;
		}
	}
}
