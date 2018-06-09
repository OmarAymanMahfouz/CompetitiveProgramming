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
int n, m;
pair<int, int> p[14], st, ed;
bool flag;
void solve(int x, int cur, bool vis[])
{
	if (x == n) { flag = true; return; }
	else if (x == n - 1)
	{
		for (int i = 0; i < m; i++)
		{
			if (!vis[i] && ((ed.first == p[i].first && p[i].second == cur)|| (ed.first == p[i].second && p[i].first == cur)))solve(x + 1, ed.second, vis);
			if (flag) return;
		}
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			if (!vis[i] && cur == p[i].first)
			{
				vis[i] = true;
				solve(x + 1, p[i].second, vis);
				vis[i] = false;
			}
			else if (!vis[i] && cur == p[i].second)
			{
				vis[i] = true;
				solve(x + 1, p[i].first, vis);
				vis[i] = false;
			}
			if (flag)
				return;
		}
	}
}
int main() {
	DO_NOT_STOP();
	while (cin >> n >> m && n)
	{
		cin >> st.first >> st.second >> ed.first >> ed.second;
		for (int i = 0; i < m; i++) cin >> p[i].first >> p[i].second;
		flag = 0;
		bool vis[15] = { 0 };
		solve(0, st.second, vis);
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
		return 0;
}