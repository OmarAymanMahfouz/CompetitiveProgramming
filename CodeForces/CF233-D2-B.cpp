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
int s(int t)
{
	int ans = 0;
	while (t) {
		ans += t % 10;
		t /= 10;
	}
	return ans;
}
int main()
{
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	fill();
	
	ll n;
	scanf("%lld", &n);
	int si = 162;
	for (ll i = sqrt(n); i >= max(0, int(sqrt(n) - si)); i--)
	{
		if (i * i + s(i) * i == n)
			return cout << i << endl, 0;
	}
	cout << -1 << endl;
	return 0;
} 