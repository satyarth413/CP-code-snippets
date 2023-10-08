#include<iostream>
#include<string>
using namespace std;

#define ll long long
const ll inf = 1e17;

const int mod = 1e9 + 7;

string curr = "";

void AllSubsets(string &s, int idx = 0)
{
	if (idx == s.size())
	{
		cout << curr << endl;
		return;
	}
	curr.push_back(s[idx]);
	AllSubsets(s, idx + 1);
	curr.pop_back();
	AllSubsets(s, idx + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string check = "ABCD";
	AllSubsets(check);
}