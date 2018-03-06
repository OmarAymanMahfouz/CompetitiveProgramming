#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define ull unsigned long long 
#define ld long double
using namespace std;
bool vis[501][501];
int main()
{
	int x, y, z;
	while (scanf("%d%d%d", &x, &y, &z))
	{
		if (x == 0 && y == 0 && z == 0)
			break;
		pair<int, int> p1, p2;
		while (z--)
		{
			cin >> p1.first >> p1.second >> p2.first >> p2.second;
			for (int i = min(p1.first, p2.first); i <= max(p1.first, p2.first); i++)
			{
				for (int j = min(p1.second, p2.second); j <= max(p1.second, p2.second); j++)
				{
					vis[i][j] = 1;
				}
			}
		}
		int c = 0;
		for (int i = 1; i <= x; i++)
			for (int j = 1; j <= y; j++)
				if (!vis[i][j])
					c++;
		if (c == 0 || c == 1)
			cout << "There is no empty spots.\n";
		else
			cout << "There are " << c << " empty spots.\n";
		memset(vis, 0, sizeof vis);
	}

	system("pause");
	return 0;
}