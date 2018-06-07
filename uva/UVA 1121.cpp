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
	int n, s;
	vector<short> vec;
	bool flag;
	while (cin >> n >> s)
	{
		vec.resize(n); flag = 0;
		for (int i = 0; i < vec.size(); i++) cin >> vec[i];
		int ans = 1e5, st = 0, cnt = 0, sum = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			while (st < vec.size() && sum < s)
			{
				sum += vec[st];
				st++;
			}
			if (sum >= s) ans = min(ans, (st - 1) - i + 1), flag = 1;;
			sum -= vec[i];
		}
		cout << (flag ? ans : 0) << endl;
	}
	return 0;
}