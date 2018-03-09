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
	int n, l, x, r;
	cin >> n >> l >> r >> x;
	vector<int>vec(n), v;
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	int c = 0, ans = 0, j, counter;
	bool flag = 0;
	for (int i = 3; i < (1 << n); i++)
	{
		j = i, c = counter = 0;
		while (j)
		{
			if (j % 2 != 0)
				c += vec[counter], v.push_back(vec[counter]);
			j /= 2;
			counter++;
		}
		sort(v.begin(), v.end());
		if (c >= l && c <= r && abs(v[v.size() - 1] - v[0]) >= x)
		{
			ans++;
		}
		v.clear();
	}
	cout << ans << endl;
	return 0;
}