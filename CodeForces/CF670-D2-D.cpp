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
void fill()
{
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
ll n, k, a[100000], b[100000];

bool check(ll x)
{
	ll cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (b[i] >= x * a[i]) continue;
		cnt += ((x * a[i]) - b[i]);
		if (cnt > k) return false;
	}
	return true;
}
ll BS(ll s, ll e, ll ans = 0)
{
	if (s <= e)
	{
		ll mid = (s + e) / 2;
		if (check(mid))
		{
			return BS(mid + 1, e, mid);
		}
		else
			return BS(s, mid - 1, ans);
	}
	return ans;
}

int main() {
	fill();
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	cout << BS(0, 1e10) << endl;
	return 0;
}