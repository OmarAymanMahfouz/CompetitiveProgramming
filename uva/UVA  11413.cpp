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
int x, y;
int vec[10001];
bool check(ll a)
{
	ll cnt = 0, sum = 0;
	for (int i = 0; i < x; i++)
	{
		if (cnt >= y) return 0;
		sum += vec[i];
		if (sum > a)sum = 0, cnt++, i--;
		else if (sum == a) {cnt++, sum = 0; continue;}
	}
	if (sum) cnt++;
	return ((cnt > y)? 0 : 1);
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
	while (cin >> x >> y)
	{
		for (int i = 0; i < x; i++)
			cin >> vec[i];
		cout << Bs() << endl;
	}
	
	return 0;
}