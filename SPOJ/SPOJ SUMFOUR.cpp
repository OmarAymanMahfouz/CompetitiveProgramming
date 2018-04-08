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
multiset<int> a, b, c, d;
int x[6300000];
int main()
{
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int n, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t); a.insert(t);
		scanf("%d", &t); b.insert(t);
		scanf("%d", &t); c.insert(t);
		scanf("%d", &t); d.insert(t);
	}
	int cnt = 0;
	for (auto e : a)
	{
		for (auto f : b)
			x[cnt++] = e + f;
	}
	sort(x, x + cnt);
	ll ans = 0;
	for (auto e : c)
	{
		for (auto f : d)
		{
			ans += (upper_bound(x, x + cnt, -(e + f)) - x) - (lower_bound(x, x + cnt, -(e + f)) - x);
		}
	}
	printf("%lld", ans);
	return 0;
}