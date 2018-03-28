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
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#define ll long long
#define ull unsigned long long 
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
	string s;
	vector<int> vec;
	int n, X, mn;
	while (cin >> n && n)
	{
		vec.resize(n);
		mn = 1e9;
		for (int i = 0; i < n; i++)
		{
			cin.ignore();
			getline(cin, s);
			X = 0;
			for (int j = 0; j < s.size(); j++)
				if (s[j] != 'X') X++;
			mn = min(mn, X);
			vec[i] = X;
		}
		X = 0;
		for (auto i : vec)
		{
			X += abs(i - mn);
		}
		cout << X << endl;
	}
	return 0;
}