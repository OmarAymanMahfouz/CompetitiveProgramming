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
int x[21][3];
int y[21];
int main()
{
	int n, m;
	while (cin >> n >> m && (n || m))
	{
		for (int i = 1; i <= n; i++)
			cin >> y[i];

		for (int i = 0; i < m; i++)
			for (int j = 0; j < 3; j++)
				cin >> x[i][j];

		for (int i = 0; i < m; i++)
			y[x[i][1]] += x[i][2], y[x[i][0]] -= x[i][2];

		sort(y, y + n+1);
		if (y[0] < 0)
			cout << "N\n";
		else
			cout << "S\n";
		memset(y, 0, sizeof y);
	}
	return 0;
}