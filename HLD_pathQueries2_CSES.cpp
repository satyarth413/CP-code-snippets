#include<bits/stdc++.h>
using namespace std;

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

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

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

#define rep(i, a, b)    for(int i = a; i < (b); ++i)
#define per(i, a, b)    for(int i = (a)-1 ; i >= (b); i--)
#define forn(i,n)       rep(i,0,n)
#define rof(i,n)        per(i,n,0)
#define ff              first
#define ss              second
#define mp              make_pair
#define all(x)          (x).begin(), (x).end()
#define endl            "\n"
// #define int             long long
#define ll              long long
#define pb              push_back
#define pii             pair<int,int>
#define setbits(x)      __builtin_popcountll(x)
#define zerbefone(x)    __builtin_ctzll(x)
#define pqb             priority_queue<int> // maxheap
#define pqs             priority_queue<int,vector<int>,greater<int>> // minheap
#define piipqs          priority_queue<pii,vector<pii>,greater<pii>> // minheap for pair<int,int>
#define piipqb          priority_queue<pii> // maxheap for pair<int,int>
#define mod             1000000007
#define inf             100000000000000000 //1e17
#define mem0(a)         memset(a,0,sizeof(a))
#define mem1(a)         memset(a,-1,sizeof(a))
#define meminf(a)       memset(a,0x7f,sizeof(a))
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// #define oset            tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937_64              rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}

ll add(ll a, ll b)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

ll sub(ll a, ll b)
{
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

ll mul(ll a, ll b)
{
    return (a * b) % mod;
}

// ****************************************** Code Begins ****************************************** //

vector<int> arr, tour;

struct node {
    //req variable
    int mx;
    //default value
    node()
    {
        mx = 0;
    }
};
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
        curr.mx = max(left.mx, right.mx);
    }

    //for leaf
    void single(node &curr, int idx) {
        curr.mx = a[idx];
    }

    void build(int index, int ss, int se) {
        if (ss == se) {
            single(tree[index], ss);
            return;
        }
        int mid = (ss + se) / 2;
        build(index << 1, ss, mid);
        build(index << 1 | 1, mid + 1, se);
        merge(tree[index], tree[index << 1], tree[index << 1 | 1]);
    }

    void build() {
        build(1, 0, n - 1);
    }

    node query(int index, int ss, int se, int qs, int qe) {
        if (qs > se || qe < ss) return neutral;
        if (qs <= ss && qe >= se) return tree[index];
        int mid = (ss + se) / 2;
        node left = query(index << 1, ss, mid, qs, qe);
        node right = query(index << 1 | 1, mid + 1, se, qs, qe);
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
        update(index << 1, idx, ss, mid);
        update(index << 1 | 1, idx, mid + 1, se);
        merge(tree[index], tree[index << 1], tree[index << 1 | 1]);
    }

    void update(int idx) {
        update(1, idx, 0, n - 1);
    }
};


segte st;

vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    tour.push_back(arr[v]);
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}

int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = st.query(pos[head[b]], pos[b]).mx;
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = st.query(pos[a], pos[b]).mx;
    res = max(res, last_heavy_path_max);
    return res;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    forn(i, n)
    cin >> arr[i];
    vector<vector<int>> adj(n);
    forn(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    init(adj);
    st.init(n);
    st.put(tour);
    st.build();
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int num, x;
            cin >> num >> x;
            num--;
            st.a[pos[num]] = x;
            st.update(pos[num]);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << (query(a, b)) << " ";
        }
    }
}

signed main()
{
    FIO;
    int tt = 1;
    // cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve();
}