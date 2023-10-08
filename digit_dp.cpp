void solve()
{
	string n;
	cin >> n;
	int d;
	cin >> d;
	int len = sz(n);
	vector<vector<int>> dp(d, vector<int>(2));
	// dp[sum][sm_already]
	// sum => sum modulo d till now(curr position)
	// sm_already => current prefix number has become smaller(than n) already?
	dp[0][0] = 1; // => 0 [ _ _ ]
	for (int pos = 0; pos < len; pos++) {
		vector<vector<int>> newdp(d, vector<int>(2));
		for (int sum = 0; sum < d; sum++) {
			for (int sm_already : {0, 1}) {
				for (int dig = 0; dig <= 9; dig++) {
					if (!sm_already && dig > n[pos] - '0')
						break; 
					add(newdp[(sum + dig) % d][sm_already || (dig < n[pos] - '0')], dp[sum][sm_already]);
				}
			}
		}
		dp.swap(newdp);
	}
	cout << (dp[0][0] + dp[0][1] - 1 + mod) % mod << endl;
}