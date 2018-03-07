#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define ull unsigned long long 
#define ld long double
using namespace std;
int x[101][101];
int main()
{
	int n;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> x[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				x[i][n] += x[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				x[n][i] += x[j][i];
		int odd = 0, row = 0;
		vector <int> vec;
		for (int i = 0; i < n; i++)
			if (x[i][n] % 2)
				odd++, row++, vec.push_back(i);
		for (int i = 0; i < n; i++)
			if (x[n][i] % 2)
				odd++, vec.push_back(i);
		if (!odd)
			cout << "OK\n";
		else if (odd == 2 && row == 1)
			cout << "Change bit (" << vec[0] + 1 << "," << vec[1] + 1 <<")\n";
		else
			cout << "Corrupt\n";
		memset(x, 0, sizeof x);
	}
	return 0;
}