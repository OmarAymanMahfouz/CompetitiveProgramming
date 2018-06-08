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
	int n, m, k, T;
	vector<int> vec;
	cin >> T;
	bool flag;
	int vis[10001];
	for (int j = 1; j <= T; j++)
	{
		flag = 0;
		cin >> n >> m >> k;
		memset(vis, 0, sizeof vis);
		vec.resize(n + 1);
		vec[1] = 1; vec[2] = 2; vec[3] = 3;
		for (int i = 4; i <= n; i++)
			vec[i] = (vec[i - 1] + vec[i - 2] + vec[i - 3]) % m + 1;
		int ans = n + 1, st = 1, cnt = 0, cnt2 = 0;
		for (int i = 1; i < vec.size(); i++)
		{
			while (st < vec.size() && cnt < k)
			{
				if (vec[st] <= k && !vis[vec[st]]) cnt++;
				vis[vec[st]]++;
				st++;
			}
			if (cnt == k) ans = min(ans, (st - 1) - i + 1), flag = 1;
			vis[vec[i]]--;
			if (!vis[vec[i]] && vec[i] <= k) cnt--;
		}
		cout << "Case " << j << ": ";
		if (flag) cout << ans << endl;
		else cout << "sequence nai\n";
	}

	return 0;
}