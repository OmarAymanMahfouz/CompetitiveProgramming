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
int x[3001];
int main()
{
	string s;
	map<int, int> mp;
	set<int> st;
	int n, cnt;
	while(cin >> s && s != "#")
	{
		cin >> n >> cnt;
		mp[n] = cnt;
		st.insert(cnt);
		x[n] = cnt;
	}
	cnt = 0;

	cin >> n;
	for (auto e : st)
	{
		for (auto i : mp)
		{
			if (i.second == e)
			{
				cout << i.first << endl;
				cnt++;
				mp[i.first] = i.second + x[i.first];
				st.insert(mp[i.first]);
			}
			if (cnt == n)
				break;
		}
		if (cnt == n)
			break;
	}
	cout << endl;
	return 0;
}