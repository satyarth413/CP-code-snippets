struct node {
	//req variable
	int one;
	//default value
	node()
	{
		one = 0;
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
	inline void merge(node &curr, node &left, node &right) {
		curr.one = left.one + right.one;
	}

	//for leaf
	inline void single(node &curr, int idx) {
		curr.one = a[idx];
	}

	void build(int index, int ss, int se) {
		if (ss == se) {
			single(tree[index], ss);
			return;
		}
		int mid = (ss + se) >> 1;
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
		int mid = (ss + se) >> 1;
		node left = query(index << 1, ss, mid, qs, qe);
		node right = query(index << 1 | 1, mid + 1, se, qs, qe);
		node mer;
		merge(mer, left, right);
		return mer;
	}

	node query(int l, int r) {
		if (l > r) return neutral;
		return query(1, 0, n - 1, l, r);
	}

	void update(int index, int idx, int ss, int se) {
		if (idx < ss || idx > se)
			return;
		if (ss == se) {
			single(tree[index], ss);
			return;
		}
		int mid = (ss + se) >> 1;
		update(index << 1, idx, ss, mid);
		update(index << 1 | 1, idx, mid + 1, se);
		merge(tree[index], tree[index << 1], tree[index << 1 | 1]);
	}

	void update(int idx) {
		update(1, idx, 0, n - 1);
	}

	// k'th starting from 1(1 base)
	int find_kth(int k) // faster than recursive one
	{
		int index = 1;
		int ss = 0, se = n - 1;
		while (ss < se)
		{
			int mid = (ss + se) / 2;
			if (tree[2 * index].one < k)
			{
				k -= tree[2 * index].one;
				index = 2 * index + 1;
				ss = mid + 1;
			}
			else
			{
				index = 2 * index;
				se = mid;
			}
		}
		assert(ss == se);
		return se;
	}
};