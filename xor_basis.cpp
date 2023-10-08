// https://codeforces.com/gym/418338/problem/B

#include <bits/stdc++.h>

typedef long double ld;
#define int long long

#define gcd            __gcd
#define endl           "\n"
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define f              first
#define s              second
#define sz(x)          (int)(x).size()
#define deci(x, y)     fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PI             3.141592653589793238
#define mem0(x)        memset(x,0,sizeof x)
#define mem1(x)        memset(x,-1,sizeof x)
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.f << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NITIN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/*
 try to think backward..
 if you arent able to come up for answer, try to fix some variable, some bits, initial starting point or end point.....
 may be break a operation into two or combine two into one
*/
const int M = 62;
int basis[M];
int cnt;

void init() {
    memset(basis, 0, sizeof basis);
    cnt = 0;
}

bool insertVector(int val) {
    for (int j = M - 1; j >= 0; j--) {
        if (!(val & (1ll << j))) continue;
        if (basis[j] == 0) {
            basis[j] = val;
            cnt++;
            return true;
        }
        val ^= basis[j];
    }
    return false;
}

int max_ele() {
    int ans = 0;
    for (int j = M - 1; j >= 0; j--) {
        if (ans & (1ll << j)) continue;
        ans ^= basis[j];
    }
    return ans;
}

bool is_in_space(int x,int pth) {
    for (int j = M - 1; j >= pth; j--) {
        if (!(x & (1ll   << j))) continue;
        if (!basis[j]) return false;
        x ^= basis[j];
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    int val = 0;
    init();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        val ^= a[i];
    }
    for(int i=M-1;i>=0;i--) {
        for (int j = 0; j < n; j++) {
            if (val & (1ll << i)) {
                if (a[j] & (1ll << i)) a[j] ^= (1ll << i);
            }
        }
    }
    for(int j=0;j<n;j++){
        insertVector(a[j]);
    }
    cout<<2*max_ele()+val<<endl;
}

int32_t main() {
    nitin;

    solve();
}