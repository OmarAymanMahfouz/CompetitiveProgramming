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
#include <unordered_map>
#include <unordered_set>
#define ll long long
#define ull unsigned long long 
#define ld long double
using namespace std;

int main()
{
	int s, n;
	cin >> s >> n;
	vector < pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	bool flag = 1;
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		if (s > v[i].first)
			s += v[i].second;
		else
		{
			flag = 0;
			break;
		}
	}
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}