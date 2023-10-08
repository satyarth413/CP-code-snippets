// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

string to_string(char c) {
	return string(1, c);
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}
template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

#define rep(i, a, b)    for(int i = (a); i < (b); ++i)
#define per(i, a, b)    for(int i = (a) ; i >= (b); i--)
#define forn(i,n)       rep(i,0,(n))
#define rof(i,n)        per(i,(n)-1,0)
#define dbg(x)          cout << #x << "=" << x << endl
#define dbg2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define dbg3(x, y,z)    cout << #x << "=" << x << "," << #y << "=" << y <<"," << #z << "=" << z << endl
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

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// **************************** Code Begins **************************** //

const int block_size = 200;
const int maxn = 3e4 + 10;
const int maxai = 1e6 + 10;

int ans;
int v[maxn];
int freq[maxai];

void remove(int x)  // TODO: remove value at idx from data structure
{
	freq[x]--;
	if (!freq[x])
		ans--;
}

void add(int x)    // TODO: add value at idx from data structure
{
	freq[x]++;
	if (freq[x] == 1)
		ans++;
}

int get_answer()  // TODO: extract the current answer of the data structure
{
	return ans;
}

struct Query {
	int l, r, idx;
	bool operator<(Query other) const
	{
		return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
	}
};

vector<int> mo_s_algorithm(vector<Query> queries) {
	vector<int> answers(queries.size());
	sort(queries.begin(), queries.end());
	// TODO: initialize data structure
	int cur_l = 0;
	int cur_r = -1;
	// invariant: data structure will always reflect the range [cur_l, cur_r]
	for (Query q : queries) {
		while (cur_l > q.l) {
			cur_l--;
			add(v[cur_l]);
		}
		while (cur_r < q.r) {
			cur_r++;
			add(v[cur_r]);
		}
		while (cur_l < q.l) {
			remove(v[cur_l]);
			cur_l++;
		}
		while (cur_r > q.r) {
			remove(v[cur_r]);
			cur_r--;
		}
		answers[q.idx] = get_answer();
	}
	return answers;
}

void solve()
{
	int n;
	cin >> n;
	forn(i, n)
	cin >> v[i];
	int q;
	cin >> q;
	vector<Query> ask(q);
	forn(i, q)
	{
		ask[i].idx = i;
		cin >> ask[i].l >> ask[i].r;
		ask[i].l--;
		ask[i].r--;
	}
	vector<int> ansvec = mo_s_algorithm(ask);
	forn(i, q)
	cout << ansvec[i] << endl;
}

signed main()
{
	FIO;
	int tt = 1;
	// cin >> tt;
	for (int i = 1; i <= tt; i++)
		solve();
}