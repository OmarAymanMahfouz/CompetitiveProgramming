#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <iomanip>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
int main()
{
	int n, y;
	cin >> n;
	vector<bool> vis(n + 1);
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int mx = 1;
		for (int j = 0; j < n; j++)
		{
			cin >> y;
			if (mx < y)
				mx = y;
		}
		if (vis[mx])
			mx++;
		vis[mx] = 1;
		vec.push_back(mx);
	}
	for (int i = 0; i < n; i++)
		cout << vec[i] << " ";
	cout << endl;

	return 0;
}