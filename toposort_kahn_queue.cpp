#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> topo(int n, vector<int> adj[]) {
		queue<int> q;
		vector<int> indegree(n, 0);
		for (int i = 0; i < n; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) { // assuming no Directed Cycles
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) {
					q.push(it);
				}
			}
		}
		return topo;
	}
};



int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int V, E;
		cin >> V >> E;

		vector<int> adj[V];

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		Solution obj;
		cout << obj.isCyclic(V, adj) << "\n";
	}

	return 0;
}
