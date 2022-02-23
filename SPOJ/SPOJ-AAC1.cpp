#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <queue>
#include <locale>
#include <deque>
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
const int oo = 2e9, MAXN = 1e4 + 5;
int n, m;
int destance[MAXN];
bool vis[MAXN];
void bfs(int x, vector<vector<int> > adj)
{
	queue<int> qu;
	qu.push(x);
	vis[x] = true;
	while (!qu.empty())
	{
		int node = qu.front();
		qu.pop();
		for (int i = 0; i < adj[node].size(); i++)
		{
			int cur = adj[node][i];
			if (!vis[cur])
			{
				vis[cur] = true;
				destance[cur] = destance[node] + 1;
				qu.push(cur);
			}
		}
	}
	return;
}

int main() {
	DO_NOT_STOP();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vector<vector<int> > adj(n + 1);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bfs(1, adj);
		cout << destance[n] << endl;
		memset(vis, false, sizeof vis);
		memset(destance, 0, sizeof destance);
	}
	return 0;
}