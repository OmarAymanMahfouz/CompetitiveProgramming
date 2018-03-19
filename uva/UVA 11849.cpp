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
	map<int, int> mp;
	int n, m, x, ans;
	while (scanf("%d%d", &n, &m) && (n || m))
	{
		ans = 0;
		mp.clear();
		for (int i = 0; i < n; i++)
			scanf("%d", &x), mp[x]++;
		for (int i = 0; i < m; i++)
			scanf("%d", &x), ans += mp[x];
		printf("%d", ans);
	}

	return 0;
}