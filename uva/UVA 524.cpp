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
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#define ll long long
#define ull unsigned long long 
#define ld long double
#define endl "\n"
using namespace std;
void DO_NOT_STOP()
{
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
bool vis[17];
set<vector<int>> s;
int n;
bool check(int x, int y)
{
	int z = x + y;
	if (z == 1) return false;
	for (ll i = 2; i * i <= z; i++)
		if (z % i == 0) return false;
	return true;
}
void solve(bool vis[], vector<int> vec)
{
	if (vec.size() == n) { s.insert(vec); return; }
	
	for (int i = 2; i <= n; i++)
	{
		if (vec.size() == n - 1)
		{
			if (!vis[i] && check(1, i) && check(vec[vec.size() - 1], i))
			{
				vis[i] = true;
				vec.push_back(i);
				solve(vis, vec);
				vec.pop_back();
				vis[i] = false;
			}
		}
		else
		{
			if (!vis[i] && check(vec[vec.size() - 1], i))
			{
				vis[i] = true;
				vec.push_back(i);
				solve(vis, vec);
				vec.pop_back();
				vis[i] = false;
			}
		}
	}
}
int main() {
	DO_NOT_STOP();
	for (int T = 1; cin >> n; T++)
	{
		if (T != 1) cout << endl;
		cout << "Case " << T << ":\n";
		vector<int> vec;
		vec.push_back(1);
		bool vis[17] = { 0 };
		solve(vis, vec);
		for (auto e : s)
		{
			for (int i = 0; i < e.size(); i++)
			{
				if (i != e.size() - 1) cout << e[i] << " ";
				else cout << e[i] << endl;
			}
		}
		s.clear();
	}
	return 0;
}