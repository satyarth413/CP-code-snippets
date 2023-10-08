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

int merge(int a[], int temp[], int l, int mid, int r)
{
	int icnt = 0;
	int i = l, j = mid, k = l;
	while (i <= (mid - 1) && j <= r)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
		{
			icnt += mid - i;
			temp[k++] = a[j++];
		}
	}
	while (i <= mid - 1)
		temp[k++] = a[i++];
	while (j <= r)
		temp[k++] = a[j++];
	for (int idx = l; idx <= r; idx++)
		a[idx] = temp[idx];
	return icnt;
}

int ms(int a[], int temp[], int l, int r)
{
	if (l >= r)
		return 0;
	int inv = 0, mid = (l + r) / 2;
	inv += ms(a, temp, l, mid);
	inv += ms(a, temp, mid + 1, r);
	inv += merge(a, temp, l, mid + 1, r);
	return inv;
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
		int n, ans = -1;
		cin >> n;
		vector<int> a(n);
		int two[n] = {0};
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			int p2 = 0;
			while (a[i] % 2 == 0)
			{
				a[i] /= 2;
				p2++;
			}
			two[n - 1 - i] = p2;
		}
		int temp[n] = {0};
		cout << ms(two, temp, 0, n - 1);
	}
}