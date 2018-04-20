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

vector<int>vec[1000001];
int main()
{
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	fill();
	int x, y;
	while (cin >> x >> y)
	{
		for (int i = 1; i <= x; i++)
		{
			int a; cin >> a;
			vec[a].push_back(i);
		}
		while (y--)
		{
			int a, b;
			cin >> a >> b;
			if (vec[b].size() < a)
				cout << 0 << endl;
			else
				cout << vec[b][a - 1] << endl;
		}
		vec->clear();
	}
	return 0;
} 