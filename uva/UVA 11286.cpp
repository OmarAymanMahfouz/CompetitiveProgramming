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
	int n, mx, ans;
	map<vector<int>, int>mp;
	vector<int>vec(5);
	while (cin >> n && n)
	{
		mx = -1e9, ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int i = 0; i < 5; i++)
				cin >> vec[i];
			sort(vec.begin(), vec.end());
			mp[vec]++;
			mx = max(mx, mp[vec]);
		}
		
		for (auto e : mp)
			if (e.second == mx)
				ans += mx;
		cout << ans << endl;
		mp.clear();
	}
	
	
	return 0;
}