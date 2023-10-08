vector<int>fac, inv, ifac;
void pre(int lim)
{
	fac.push_back(1); fac.push_back(1);
	ifac.push_back(1); ifac.push_back(1);
	inv.push_back(0); inv.push_back(1);
	for (int i = 2; i <= lim; i++)
	{
		fac.push_back(fac.back()*i % mod);
		inv.push_back(mod - (inv[mod % i] * (mod / i) % mod));
		ifac.push_back(ifac.back()*inv.back() % mod);
	}
}
int ncr(int n, int r)
{
	if (n < r || n < 0)
		return 0;
	if (r == 0)
		return 1;
	return (((fac[n] * ifac[r]) % mod) * ifac[n - r]) % mod;
}
