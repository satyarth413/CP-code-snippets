#include <iostream>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
	int n, k;
	cin >> n >> k;
	// Ordered set declared with name o_set
	ordered_set o_set;
	for (int i = 1; i <= n; i++)
		o_set.insert(i);

	// Finding the second smallest element
	// in the set using * because
	// find_by_order returns an iterator
	int idx = 0;
	for (int i = 1; i <= n; i++)
	{
		idx = (idx + k) % (n - i + 1);
		int num = *(o_set.find_by_order(idx));
		cout << num << " ";
		o_set.erase(num);
	}
	return 0;
}
