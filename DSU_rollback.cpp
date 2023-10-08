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