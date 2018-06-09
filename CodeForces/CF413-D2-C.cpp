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
void DO_NOT_STOP()
{
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int arr[101], x[101];
int main() {
	DO_NOT_STOP();
	ll n, m, sum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i], sum += arr[i];
	for (int i = 0; i < m; i++)
	{
		int t; cin >> t;
		 sum -= arr[t - 1];
		 x[i] = arr[t - 1];
	}
	sort(x, x + m);
	for (int i = m - 1; i >= 0; i--)
		sum += max(sum, (ll)x[i]);
	cout << sum << endl;

	return 0;
}