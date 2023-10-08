// Taken from
// https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/

// For Euler Path (doesn't need to start and end at same)
// https://cp-algorithms.com/graph/euler_path.html#implementation 


// C++ program to print Eulerian circuit in given
// directed graph using Hierholzer algorithm
#include <bits/stdc++.h>
using namespace std;

// Function to print Eulerian circuit
void printCircuit(vector<int> adj[], int n)
{
	// adj represents the adjacency list of
	// the directed graph

	if (n == 0)
		return; // empty graph

	// Maintain a stack to keep vertices
	// We can start from any vertex, here we start with 0
	vector<int> curr_path;
	curr_path.push_back(0);

	// list to store final circuit
	vector<int> circuit;

	while (curr_path.size() > 0) {
		int curr_v = curr_path[curr_path.size() - 1];

		// If there's remaining edge in adjacency list
		// of the current vertex
		if (adj[curr_v].size() > 0) {
			// Find and remove the next vertex that is
			// adjacent to the current vertex
			int next_v = adj[curr_v].back();
			adj[curr_v].pop_back();

			// Push the new vertex to the stack
			curr_path.push_back(next_v);
		}

		// back-track to find remaining circuit
		else {
			// Remove the current vertex and
			// put it in the circuit
			circuit.push_back(curr_path.back());
			curr_path.pop_back();
		}
	}

	// we've got the circuit, now print it in reverse
	for (int i = circuit.size() - 1; i >= 0; i--) {
		cout << circuit[i];
		if (i)
			cout << " -> ";
	}
}

// Driver Code
int main()
{
	// Input Graph 1
	int n1 = 3;
	vector<int> adj1[n1];

	// Build the edges
	adj1[0].push_back(1);
	adj1[1].push_back(2);
	adj1[2].push_back(0);
	printCircuit(adj1, n1);
	cout << endl;

	// Input Graph 2
	int n2 = 7;
	vector<int> adj2[n2];

	adj2[0].push_back(1);
	adj2[0].push_back(6);
	adj2[1].push_back(2);
	adj2[2].push_back(0);
	adj2[2].push_back(3);
	adj2[3].push_back(4);
	adj2[4].push_back(2);
	adj2[4].push_back(5);
	adj2[5].push_back(0);
	adj2[6].push_back(4);
	printCircuit(adj2, n2);
	cout << endl;
	return 0;
}

// This code is contributed by sanjanasikarwar24
