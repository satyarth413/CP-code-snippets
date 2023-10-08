class string_hashing {
public:
	string s;
	int n;
	int p[2] = {31, 43};
	int mods[2] = {1000000007, 998244353};
	vector<int> suff[2], p_pow[2];

	void init(string &S)
	{
		s = S;
		n = (int)s.size();
		for (int i = 0; i < 2; i++)
		{
			suff[i].assign(n + 2, 0);
			p_pow[i].assign(n + 1, 0);
		}
		build_suff();
		build_p_pow();
	}

	void build_suff() // 1 based idx , with suff[v][n+1]=0 , whole string hash in suff[v][1]
	{
		for (int v = 0; v < 2; v++)
			for (int i = n; i >= 1; i--)
				suff[v][i] = ((s[i - 1] - 'a' + 1) + suff[v][i + 1] * p[v]) % mods[v];
	}

	void build_p_pow()
	{
		for (int v = 0; v < 2; v++)
		{
			p_pow[v][0] = 1;
			for (int i = 1; i <= n; i++)
				p_pow[v][i] = (p_pow[v][i - 1] * p[v]) % mods[v];
		}
	}

	pii calc_hash(string &str)
	{
		array<int, 2> hash = {0, 0};
		for (int v = 0; v < 2; v++)
		{
			int curr_pow = 1;
			for (int i = 0; i < sz(str); i++)
			{
				hash[v] = (hash[v] + curr_pow * (str[i] - 'a' + 1)) % mods[v];
				curr_pow = (curr_pow * p[v]) % mods[v];
			}
		}
		return {hash[0], hash[1]};
	}

	pii sub_hash(int l, int r) // l,r => 0 indexed
	{
		if (l > r)
			return {0, 0};
		array<int, 2> hash;
		for (int v = 0; v < 2; v++)
		{
			hash[v] = (suff[v][l + 1] - suff[v][r + 2] * p_pow[v][r - l + 1]) % mods[v];
			if (hash[v] < 0)
				hash[v] += mods[v];
		}
		return {hash[0], hash[1]};
	}
};
