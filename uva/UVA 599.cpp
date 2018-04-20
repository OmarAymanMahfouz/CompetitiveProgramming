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
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#define ll long long
#define ull unsigned long long 
#define ld long double
#define endl "\n"
using namespace std;
void fill()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
int component[26];
int main()
{
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	fill();
	int T;
	cin >> T;
	while (T--)
	{
		vector<char> adj[26];
		memset(component, 0, sizeof component);
		int tree = 0, acorn = 0;
		string s;
		while (true)
		{
			cin >> s;
			if (s[0] == '*') break;
			char x, y;
			x = s[1], y = s[3];
			if (x == y) continue;
			adj[x - 'A'].push_back(y);
			adj[y - 'A'].push_back(x);
		}
		cin >> s;
		queue<char> qu;
		for (int i = 0; i < s.size(); i += 2)
		{
			if (component[s[i] - 'A'] > 0 || adj[s[i] - 'A'].empty()) continue;
			tree++;
			qu.push(s[i]);
			component[s[i] - 'A'] = tree;
			while (!qu.empty())
			{
				char a = qu.front();
				qu.pop();
				for (int j = 0; j < adj[a - 'A'].size(); j++)
				{
					char x = adj[a - 'A'][j];
					if (component[x - 'A'] > 0) continue;
					qu.push(x);
					component[x - 'A'] = tree;
				}
			}
		}
		for (int i = 0; i < s.size(); i += 2)
			if (component[s[i] - 'A'] == 0)
				acorn++;

		printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
	}

	return 0;
}