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
ll x, y, arr[100001], arr2[100001];
pair<bool,ll> check(ll a)
{
	for (ll i = 0; i < x; i++)
		arr2[i] = arr[i] + ((i + 1) * a);
	ll sum = 0;
	sort(arr2, arr2 + x);
	for (int i = 0; i < a; i++) sum += arr2[i];
	return ((sum > y) ? make_pair(0, sum) : make_pair(1, sum));
}
void Bs(int s, int e, pair<ll, ll> &ans)
{
	while (s <= e)
	{
		ll mid = (s + e) / 2;
		pair <bool, ll>x = check(mid);

		if (x.first)
		{
			ans = make_pair(mid, x.second);
			s = mid + 1;
		}
		else e = mid - 1;
	}
}
int main() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	fill();
	cin >> x >> y;
	for (int i = 0; i < x; i++)
		cin >> arr[i];
	pair<ll, ll> pi;
	Bs(0, x, pi);
	cout << pi.first << " " << pi.second << endl;
	return 0;
}