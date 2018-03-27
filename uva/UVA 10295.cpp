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
	map<string, int> mp;
	int n, m, x;
	string s;
	cin >> n >> m;
	while (n--)
	{
		cin >> s >> x;
		mp[s] = x;
	}
	while (m--)
	{
		n = 0;
		while (cin >> s && s != ".")
		{
			if (mp[s] != 0)
				n += mp[s];
		}
		cout << n << endl;
	}
	return 0;
}