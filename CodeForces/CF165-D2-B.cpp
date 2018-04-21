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
ll x, y;
bool check(ll a)
{
	ll c = 1, cnt = a, ans = a;
	while (ans)
	{
		ans = a / pow(y, c++);
		cnt += ans;
	}
	return ((cnt >= x) ? 1 : 0);
}
int Bs(int s = 0, int e = 1e9, int ans = 1e9)
{
	if (s <= e)
	{
		int mid = (s + e) / 2;
		if (check(mid))
		{
			ans = Bs(s, mid - 1, mid);
		}
		else
			ans = Bs(mid + 1, e, ans);
	}
	return ans;
}
int main() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	fill();
	cin >> x >> y;
	cout << Bs() << endl;
	
	return 0;
}