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
	int n, cnt = 0; string s;
	cin >> n >> s;
	map<char, int> mp;
	for (int i = 0; i < s.size(); i++)
		mp[s[i]] = 1;
	cnt = mp.size();
	mp.clear();
	int st = 0, ans = 1e5, cnt2 = 0;
	for (int i = 0; i < s.size(); i++)
	{
		while (st < s.size() && cnt2 < cnt)
		{
			if (!mp[s[st]])cnt2++;
			mp[s[st]]++;
			st++;
		}
		if (cnt2 == cnt) ans = min(ans, (st - 1) - i + 1);
		mp[s[i]]--;
		if (!mp[s[i]]) cnt2--;
	}
	cout << ans << endl;
	return 0;
}