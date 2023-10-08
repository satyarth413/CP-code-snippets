const int maxn=2e5+5;
const int logn=19;
int n;
vector<int> adj[maxn];
int dep[maxn];
int par[maxn][logn];

void dfs(int u,int dad) {
    par[u][0]=dad;
    for(auto nbr:adj[u])
    {
        if(nbr!=dad)
        {
            dep[nbr]=dep[u]+1;
            dfs(nbr,u);
        }
    }
}

void build(int root=0) { // nodes 0 indexed : 0,1,..,n-1 
    dep[root]=0;
    dfs(root,root);
    for(int j=1;j<logn;j++){
        for(int i=0;i<n;i++){
            par[i][j]=par[par[i][j-1]][j-1];
        }
    }
}

int get_kp(int node,int k) {
    for(int j=logn-1;j>=0;j--)
        if(k&(1ll<<j))
            node=par[node][j];
    return node;
}

int lca(int x,int y) {
    if(dep[x]<dep[y]) swap(x,y);
    x= get_kp(x,dep[x]-dep[y]);
    if(x==y) return x;
    for(int j=logn-1;j>=0;j--){
        if(par[x][j]!=par[y][j]){
            x=par[x][j];
            y=par[y][j];
        }
    }
    return par[x][0];
}

int dist(int x,int y) {
    int l=lca(x,y);
    return dep[x]+dep[y]-2*dep[l];
}

void solve() {
    int q;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int val;
        cin>>val;
        --val;
        adj[val].push_back(i);
        adj[i].push_back(val);
    }
    build(0);
    while(q--){
        int x,y;
        cin>>x>>y;
        --x;--y;
        cout<<lca(x,y)+1<<endl;
    }
}