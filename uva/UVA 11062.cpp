#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define ll long long
#define ull unsigned long long 
#define ld long double
using namespace std;
int main()
{
	string t, s;
	while (cin >> t)
	{
		for (int i = 0; i < t.length(); i++)
		{
			if (t[i] >= 'A' && t[i] <= 'Z')
				t[i] += 32;
		}
		if (t[t.size() - 1] == '-')
			t.pop_back(), s += t;
		else
			s += t + " ";
	}
	vector<bool> vis(s.length());
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-' || (s[i] >= 'a' && s[i] <= 'z'))
			continue;
		else
			vis[i] = 1;
	}
	set<string> ans;
	bool f;
	t = "";
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