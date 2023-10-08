// https://codeforces.com/gym/100551/problem/A

#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(lli i=0;i<n;++i)
#define rep(i,a,b) for(lli i=a;i<=b;++i)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define endl '\n'
typedef long long lli;        typedef long double ld;
typedef pair<lli,lli> ii;     typedef vector<lli> vi;
typedef vector<ii> vii;       typedef vector<vi> graph;
long long MOD=1000000007;     long double EPS=1e-9;
#define debarr(a,n) cerr<<#a<<" : ";for(lli i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cerr<<#mat<<" :\n";for(lli i=0;i<row;i++) {for(lli j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {lli idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
lli binpow(lli b,lli p,lli mod){lli ans=1;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}

void pre(){

}

#define MAXN 300001
struct DSUrollback{
	int n;
	int parent[MAXN],rank[MAXN];
	vii stack;
	int cur=-1;
	int comp;
	int compsz[MAXN];
	void init(int n){
		cur=-1;
		comp=n;
		rep(i,0,n){parent[i]=i;rank[i]=1;}
	}
	int find(int x){
		if(x!=parent[x]){return find(parent[x]);}
		else{return x;}
	}
	void merge(int x,int y){
		int xroot=find(x),yroot=find(y);
		//pr("merge",x,y,xroot,yroot);
		if(xroot!=yroot){
			if(rank[xroot]>rank[yroot]){
				parent[yroot]=xroot;
				rank[xroot]+=rank[yroot];
				stack.EB(MP(yroot,xroot));
			}else{
				parent[xroot]=yroot;
				rank[yroot]+=rank[xroot];
				stack.EB(MP(xroot,yroot));
			}
			cur++;
			compsz[cur]=comp;
			comp--;
		}
	}
	void rollback(int st){
		//pr(st);
		while(cur>st){
			parent[stack[cur].F]=stack[cur].F;
			rank[stack[cur].S]-=rank[stack[cur].F];
			comp=compsz[cur];
			cur--;stack.pop_back();
		}
	}
	void debug(){
		pr(comp,cur,stack);
		debarr(parent,n+1);
	}
}curuf;

vii answers;

vii t[1200001];
int query[300001];

ii eed;
void update(int id,int l,int r,int lq,int rq){
	//pr(id,l,r,lq,rq);
	if(lq>r||l>rq)return;
	if(lq<=l&&r<=rq){
		t[id].EB(eed);
		return;
	}
	int mid=(l+r)>>1;
	update(id<<1,l,mid,lq,rq);
	update(id<<1|1,mid+1,r,lq,rq);
}


void dfs(int id,int l,int r){
	//pr(id,l,r);
	int prev=curuf.cur;
	for(auto v:t[id]){
		curuf.merge(v.F,v.S);
	}
	if(l==r){
		if(query[l]!=-1){
			answers.EB(MP(query[l],curuf.comp));
		}
	}else{
		int mid=(l+r)>>1;
		dfs(id<<1,l,mid);
		dfs(id<<1|1,mid+1,r);
	}
	//curuf.debug();
	curuf.rollback(prev);
}

void solve(){
	lli n,k;
	cin>>n>>k;
	curuf.init(n);
	map<ii,int> mp;
	mset(query,-1);
	//pr("here");
	fr(i,k){
		char ch;
		cin>>ch;
		//pr(i);
		if(ch=='+'){
			int a,b;
			cin>>a>>b;
			if(a>b)swap(a,b);
			mp[MP(a,b)]=i;
		}else if(ch=='-'){
			int a,b;
			cin>>a>>b;
			if(a>b)swap(a,b);
			eed=MP(a,b);
			//pr(eed,mp[eed],i);
			update(1,0,k,mp[eed],i);
			//pr(eed);
			if(mp.find(eed)!=mp.end())mp.erase(mp.find(eed));
		}else{
			query[i]=i;
		}
	}
	//pr(mp);
	for(auto v:mp){
		eed=v.F;
		update(1,0,k,v.S,k);
	}
	dfs(1,0,k);
	sort(all(answers));
	for(auto v:answers){
		cout<<v.S<<endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("connect.in","r",stdin);freopen("connect.out","w",stdout);
	pre();lli t=1;//cin>>t;
	for(lli i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
		solve();
	}
}