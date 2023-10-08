// https://codeforces.com/contest/1615/problem/D

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
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
	x%=mod;
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

class dsu {
public:
    vector<pii> parent;
    vector<int> size;
    vector<int> rank;

    explicit dsu(int a) {
        parent.resize(a);
        size.resize(a);
        rank.resize(a);
        for (int i = 0; i < a; i++) {
            parent[i] = {i,0}; // p.second -> value for upward edge from i
            size[i] = 1;
            rank[i] = 0;
        }
    }

    int oper(int a,int b)
    {
    	return a^b;
    }

    pii par(int i) {
        if (i == parent[i].ff)
            return {i,0}; // p.second -> default operation value
        auto [leader,diff] = par(parent[i].ff);
        return parent[i] = make_pair(leader,oper(diff,parent[i].ss));
    }

    bool unite(int a, int b,int c) { // returns true if info is consistent
        auto [pa,wa] = par(a);
        auto [pb,wb] = par(b);
        if (pa != pb) {
        	a=pa;
        	b=pb;
            if (rank[a] > rank[b])
                swap(a, b);
            parent[a] = {b,c^wa^wb};
            size[b] += size[a];
            size[a] = 0;
            if (rank[a] == rank[b])
                rank[b]++;
            return true;
        }
        return (c==oper(wa,wb));
    }
};

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<array<int,3>> edges;
	forn(i,n-1)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back({u,v,w});
	}
	dsu d(n+1);
	bool flag=1;
	forn(i,m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(!d.unite(u,v,w))
			flag=0;
	}
	if(!flag)
		NO;
	for(auto &[u,v,w]:edges)
	{
		if(w!=-1 && !d.unite(u,v,setbits(w)%2))
			NO;
	}
	cout<<"YES"<<endl;
	for(auto &[u,v,w]:edges)
	{
		if(w==-1)
		{
			auto [pu,wu]=d.par(u);
			auto [pv,wv]=d.par(v);
			if(pu==pv)
				w=((1<<(wu^wv))-1);
			else 
			{
				d.unite(u,v,0);
				w=0;		
			}
		}
		cout<<u<<" "<<v<<" "<<w<<endl;
	}
}

signed main()
{
	FIO;
	int tt = 1;
	cin >> tt;
	for (int i = 1; i <= tt; i++)
		solve();
}