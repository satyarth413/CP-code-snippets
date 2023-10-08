// https://cses.fi/problemset/task/1736

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
#define lb             lower_bound
#define ub             upper_bound
#define ins            insert
#define sz(x)          (int)(x).size()
#define mk             make_pair
#define deci(x, y)     fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PI             3.141592653589793238
#define mem0(x)        memset(x,0,sizeof x)
#define mem1(x)        memset(x,-1,sizeof x)
#define pr             pair<int,int>
#define vi             vector<int>
#define vvi            vector<vi>
#define vpr            vector<pr>
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
 
 
vector<pair<int,int>>upd;
int n,q;
vector<int>p;
vector<int>a;
void reflect_upd(){
    vector<int>tp(n+1,0);
    for(auto &c:upd){
        tp[c.first]+=1;
        tp[c.second+1]-=1;
    }
    for(int i=1;i<=n;i++) tp[i]+=tp[i-1];
    for(auto &c:upd){
        tp[c.second+1]-=(c.second-c.first+1);
    }
    for(int i=1;i<=n;i++) tp[i]+=tp[i-1];
    for(int i=1;i<=n;i++) tp[i]+=tp[i-1];
    for(int i=0;i<n;i++) p[i]+=tp[i];
    upd.clear();
}
int qry(int l,int r){
    int tot=p[r];
    if(l-1>=0) tot-=p[l-1];
    for(auto &c:upd){
        int L=c.first;
        int R=c.second;
        int left=max(l,L);
        int right=min(r,R);
        if(right<left) continue;
        int N=right-left+1;
        if(L>=l){
            tot+=(N*(N+1))/2;
        }else{
            int A=l-L+1;
            tot+=(N*(2*A+(N-1)))/2;
        }
    }
    return tot;
}
 
void solve() {
    cin>>n>>q;
    int B=sqrt(q);
    for(int i =0;i<n;i++){
        int val;
        cin>>val;
        a.push_back(val);
        p.push_back(val);
    }
    for(int i=1;i<n;i++){
        p[i]+=p[i-1];
    }
    for(int i=0;i<q;i++){
        if(i%B==0){
            reflect_upd();
        }
        int t,l,r;
        cin>>t>>l>>r;
        --l;--r;
        if(t==1){
            upd.push_back({l,r});
        }else{
            cout<<qry(l,r)<<endl;
        }
 
    }
}
 
int32_t main() {
    nitin;
 
    solve();
}