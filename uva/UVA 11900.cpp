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
int main() {
	DO_NOT_STOP();
	int T, n, p, q;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n >> p >> q;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			if (cnt1 < p && cnt2 + x <= q)
			{
				cnt1++;
				cnt2 += x;
			}
		}
		cout << "Case " << k << ": " << cnt1 << endl;
	}
	return 0;
}