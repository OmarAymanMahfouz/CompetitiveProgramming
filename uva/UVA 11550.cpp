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
bool adj[8][24], vis[8][24];
int main()
{
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	fill();
	int T, x, y;
	vector<int>vec;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &x, &y);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				scanf("%d", &adj[i][j]);
		bool flag = 1;
		for (int i = 0; i < y; i++)
		{
			vec.clear();
			for (int j = 0; j < x; j++)
				if (adj[j][i]) vec.push_back(j);
			if (vec.size() != 2) { flag = 0; break; }
			else if (vis[vec[0]][vec[1]]) { flag = 0; break; }
			else vis[vec[0]][vec[1]] = 1;
		}
		if (flag) printf("Yes\n");
		else printf("No\n");
		memset(vis, 0, sizeof vis);
		memset(adj, 0, sizeof adj);
	}
	return 0;
} 