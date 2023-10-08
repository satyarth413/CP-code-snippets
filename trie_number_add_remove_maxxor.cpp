#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf = 2e17;

const int mod = 1e9 + 7;

class Node {
public:
	int left = 0, right = 0, cnt = 0;
};

const int mxn = (1e5 + 10) * 31;
Node a[mxn];
int ptr = 2; // 1 is ROOT and 0 acts as NULL

class Trie {
public:
	void insert(int x)
	{
		int curr = 1;
		for (int i = 30; i >= 0; i--)
		{
			if ((x & (1 << i)) == 0)
			{
				if (!a[curr].left)
					a[curr].left = ptr++;
				curr = a[curr].left;
			}
			else
			{
				if (!a[curr].right)
					a[curr].right = ptr++;
				curr = a[curr].right;
			}
			a[curr].cnt++;
		}
	}
	void remove(int x) // guaranteed that x is in trie
	{
		int curr = 1;
		for (int i = 30; i >= 0; i--)
		{
			if ((x & (1 << i)) == 0)
				curr = a[curr].left;
			else curr = a[curr].right;
			a[curr].cnt--;
		}
	}
	int max_xor(int x)
	{
		int curr = 1;
		int ans = 0;
		for (int i = 30; i >= 0; i--)
		{
			if ((x & (1 << i)) == 0)
			{
				if (a[a[curr].right].cnt > 0) // direct checking is faulty bcoz of remove, hence, this way
				{
					curr = a[curr].right;
					ans |= (1 << i);
				}
				else curr = a[curr].left; // left is surely present
			}
			else
			{
				if (a[a[curr].left].cnt > 0)
				{
					curr = a[curr].left;
					ans |= (1 << i);
				}
				else curr = a[curr].right;
			}
		}
		return ans;
	}

};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	Trie t;
	t.insert(0);
	while (q--)
	{
		char type;
		cin >> type;
		int x;
		cin >> x;
		if (type == '+')
			t.insert(x);
		else if (type == '-')
			t.remove(x);
		else cout << t.max_xor(x) << endl;
	}
}