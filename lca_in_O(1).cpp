// do tme=0, ord.clear() and adj[i].clear()
const int maxn=2e5+5;
const int logn=19;
int n,tme; 
vector<int> adj[maxn];
int tin[maxn],tout[maxn],dep[maxn],L[2*maxn];
int tab[2*maxn][logn];
vector<int> ord;

void dfs(int node,int p){
    tin[node]=tme++;
    ord.push_back(node);
    for(auto &c:adj[node]){
        if(c!=p){
            dep[c]=dep[node]+1;
            dfs(c,node);
            tme++;
            ord.push_back(node);
        }
    }
    tout[node]=tme;
}

void build(){ // 0 based nodes
	dep[0]=0;
    dfs(0,-1);
    for(int i=2;i<=sz(ord);i++){
        L[i]=L[i/2]+1;
    }
    for(int i=0;i<sz(ord);i++){
        tab[i][0]=ord[i];
    }
    for(int j=1;j<logn;j++){
        for(int i=0;i+(1<<j)-1<sz(ord);i++){
            int x=tab[i][j-1];
            int y=tab[i+(1<<(j-1))][j-1];
            if(dep[x]<dep[y]){
                tab[i][j]=x;
            }else{
                tab[i][j]=y;
            }
        }
    }
}

int lca(int u,int v){ // 0 based
    if(tin[u]>tin[v]) swap(u,v);
    int l=tin[u],r=tin[v];
    int lg=L[r-l+1];
    int x=tab[l][lg];
    int y=tab[r-(1<<lg)+1][lg];
    if(dep[x]<dep[y]){
        return x;
    }else{
        return y;
    }
}

int dist(int x,int y){
	int l=lca(x,y);
	return dep[x]+dep[y]-2*dep[l];
}

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int val;
        cin>>val;
        --val;
        adj[val].push_back(i);
        adj[i].push_back(val);
    }
    build();
    while(q--){
        int x,y;
        cin>>x>>y;
        --x;--y;
        cout<<lca(x,y)+1<<endl;
    }
}