//1-base
class fente {
public:
	int n;
	vector<int> tree;

	void init(int _n) {
		n = _n;
		tree.resize(n + 5, 0);
	}

	void update(int idx, int inc) {
		for (int i = idx; i <= n; i += i & -i)
			tree[i] += inc;
	}

	int query(int idx) {
		int sum = 0;
		assert(idx <= n);
		for (int i = idx; i >= 1; i -= i & -i)
			sum += tree[i];
		return sum;
	}

	int find_kth(int k) // 1 based k'th
	{
		int pos = 0, sum = 0;
		for (int p2 =  1 << 17; p2 >= 1; p2 >>= 1)
		{
			if ((pos + p2 <= n) && (sum + tree[pos + p2] < k))
			{
				sum += tree[pos + p2];
				pos |= p2;
			}
		}
		pos++;
		return pos;
	}
};