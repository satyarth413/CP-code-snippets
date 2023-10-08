/* Program to implement a stack using
two queue */
#include <bits/stdc++.h>

using namespace std;

class Stack {
	// Two inbuilt queues
	queue<int> q1;

	// To maintain current number of
	// elements
	int curr_size;

public:
	Stack()
	{
		curr_size = 0;
	}

	void push(int x)
	{
		curr_size++;
		queue<int> q;
		// Push x first in empty q2
		q.push(x);

		// Push all the remaining
		// elements in q1 to q2.
		while (!q1.empty()) {
			q.push(q1.front());
			q1.pop();
		}

		// swap the names of two queues
		q1 = q;
	}

	void pop()
	{

		// if no elements are there in q1
		if (q1.empty())
			return;
		q1.pop();
		curr_size--;
	}

	int top()
	{
		if (q1.empty())
			return -1;
		return q1.front();
	}

	int size()
	{
		return curr_size;
	}
};

// Driver code
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << "current size: " << s.size()
	     << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.push(4);
	// s.pop();
	cout << s.top() << endl;

	cout << "current size: " << s.size()
	     << endl;
	return 0;
}
// This code is contributed by Chhavi