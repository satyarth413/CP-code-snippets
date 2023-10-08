struct node {
	//req variable
	int val;
	//default value
	node()
	{
		val = inf; // neutral value for query function
	}
};
 
class segte {
public:
	int n{};
	vector<node> tree; // exact demanded answer in query
	vector<int> lazy; // value to be propagated in convenient form
	vector<int> a;
	vector<bool> prsnt;
	node neutral;
 
	void init(int N) {
		n = N;
		a.resize(n);
		tree.resize(4 * n + 1); // change if array value's != neutral value of node
		//default values
		lazy.assign(4 * n + 1, 0);
		prsnt.assign(4 * n + 1, false);
	}
 
	//merge function
	static void merge(node &curr, node &left, node &right) { // query function
		curr.val = min(left.val, right.val);
	}
 
	void prop(int index, int ss, int se)
	{
		tree[index].val += lazy[index]; // update function
		if (ss != se)
		{
			lazy[index << 1] += lazy[index];
			lazy[index << 1 | 1] += lazy[index];
			prsnt[index << 1] = prsnt[index << 1 | 1] = true;
		}
		lazy[index] = 0;
		prsnt[index] = false;
	}
 
	void build(int index, int ss, int se) {
		if (ss == se) {
			tree[index].val = a[ss];
			return;
		}
		int mid = (ss + se) / 2;
		build(index << 1, ss, mid);
		build(index << 1 | 1, mid + 1, se);
		merge(tree[index], tree[index << 1], tree[index << 1 | 1]);
	}
 
	void build() { // do for initial config of array if req.
		build(1, 0, n - 1);
	}
 
	node query(int index, int ss, int se, int qs, int qe)
	{
		if (prsnt[index])
			prop(index, ss, se);
		if (qs > se || qe < ss) return neutral;
		if (qs <= ss && qe >= se) {
			return tree[index];
		}
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
 
	void update(int index, int ss, int se, int l, int r, int inc) {
		if (prsnt[index])
			prop(index, ss, se);
		if (r < ss || l > se)
			return;
		if (ss >= l && se <= r) {
			prsnt[index] = true;
			lazy[index] = inc; // update function
			prop(index, ss, se);
			return;
		}
		int mid = (ss + se) / 2;
		update(index << 1, ss, mid, l, r, inc);
		update(index << 1 | 1, mid + 1, se, l, r, inc);
		merge(tree[index], tree[index << 1], tree[index << 1 | 1]);
	}
 
	void update(int l, int r, int inc) {
		update(1, 0, n - 1, l, r, inc);
	}
 
	node get(int pos, int index, int ss, int se)
	{
		if (prsnt[index])
			prop(index, ss, se);
		if (ss == se)
			return tree[index];
		node res;
		int mid = (ss + se) / 2;
		if (pos <= mid)
			res = get(pos, index << 1, ss, mid);
		else
			res = get(pos, index << 1 | 1, mid + 1, se);
		return res;
	}
 
	node get(int pos) {
		return get(pos, 1, 0, n - 1);
	}
};