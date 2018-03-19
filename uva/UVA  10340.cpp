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
bool solve(string s, string t)
{
	int ss = 0;
	for (int i = 0; i < t.length() && ss < s.length(); i++)
		if (t[i] == s[ss])
			ss++;
	if (ss == s.length())
		return true;
	return false;
}
int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		if (solve(s, t))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}