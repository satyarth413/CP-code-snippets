// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,mmx")
// #pragma GCC optimize("unroll-loops")

#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif

#define rep(i, a, b)    for(int i = (a); i < (b); ++i)
#define per(i, a, b)    for(int i = (a) ; i >= (b); i--)
#define forn(i,n)       rep(i,0,(n))
#define rof(i,n)        per(i,(n)-1,0)
#define ff              first
#define ss              second
#define mp              make_pair
#define all(x)          (x).begin(), (x).end()
#define sz(x)           (int)(x).size()
#define endl            "\n"
#define int             long long
#define ll              long long
#define pii             pair<int,int>
#define setbits(x)      __builtin_popcountll(x)
#define pqb             priority_queue<int> // maxheap
#define pqs             priority_queue<int,vector<int>,greater<int>> // minheap
#define piipqs          priority_queue<pii,vector<pii>,greater<pii>> // minheap for pair<int,int>
#define piipqb          priority_queue<pii> // maxheap for pair<int,int>
#define mod             1000000007
// #define mod             998244353
#define memt(a)         memset(a,true,sizeof(a))
#define memf(a)         memset(a,false,sizeof(a))
#define mem0(a)         memset(a,0,sizeof(a))
#define mem1(a)         memset(a,-1,sizeof(a))
#define meminf(a)       memset(a,0x7f,sizeof(a))
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0)
#define getunique(v)    {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define NO 				{cout<<"NO"<<endl; return;}
#define YES 			{cout<<"YES"<<endl; return;}
#define NEG1 			{cout<<"-1"<<endl; return;}
// #define oset            tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // set
// #define osetpii         tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> //like multiset
mt19937 				rng(chrono::steady_clock::now().time_since_epoch().count());
// for long long use mt19937_64 and usage - just do rng()

typedef tuple<int, int> tpl;

const ll inf = 2e18; //2e18
const double epsilon = 1e-7;

template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}

inline ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}

int mypow(int x, int y)
{
	x %= mod;
	int res = 1;
	while (y)
	{
		if (y & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return res;
}

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// **************************** Code Begins **************************** //

void solve()
{
	int n;
	cin >> n;
	cout << n << endl;
}

signed main()
{
	FIO;
	// freopen("i1.txt","r",stdin);
	// freopen("o1.txt","w",stdout);
	int tt = 1;
	cin >> tt;
	for (int i = 1; i <= tt; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}