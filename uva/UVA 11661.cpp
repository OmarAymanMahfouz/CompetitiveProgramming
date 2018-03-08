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
	int n;
	string s;
	bool flag1, flag2;
	while (cin >> n && n)
	{
		cin >> s;
		int ans = 1e9, c = 0;
		flag1 = flag2 = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'Z') { ans = 0; break; }
			else if (s[i] == 'R' && !flag1 && !flag2) { c++; flag1 = 1; }
			else if (s[i] == 'R' && flag1 && !flag2) { c = 1; }
			else if (s[i] == 'R' && flag2) { ans = min(ans, c); c = 1; flag1 = 1; flag2 = 0; }
			else if (s[i] == 'D' && !flag1 && !flag2) { c++; flag2 = 1; }
			else if (s[i] == 'D' && !flag1 && flag2) { c = 1; }
			else if (s[i] == 'D' && flag1) { ans = min(ans, c); c = 1; flag2 = 1; flag1 = 0; }
			else if (flag1 || flag2) c++;
		}

		cout << ans << "\n";
	}
	return 0;
}