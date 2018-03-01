#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <iomanip>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
int main()
{
	string t, s;
	int x = 4;
	while (x-- != 0)
	{
		cin >> t;
		for (int i = 0; i < t.length(); i++)
		{
			if (t[i] >= 'A' && t[i] <= 'Z')
				t[i] += 32;
		}
		s += t + " ";
	}
	vector<bool> vis(s.length());
	set<string> ans;
	int prev = 0, next = 0;
	t = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			continue;
		}
		else
		{
			vis[i] = 1;
		}
	}
	bool f = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (!vis[i])
			t += s[i], f = 1;
		else if (f)
		{
			ans.insert(t);
			t = "";
			f = 0;
		}
	}
	for (set<string> ::iterator it = ans.begin(); it != ans.end(); it++)
		cout << *it << endl;
	
	return 0;
}