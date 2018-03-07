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
int main()
{
	int T, x, y;
	int ans, j, c;
	vector<int> vec;
	bool flag;
	cin >> T;
	while (T--)
	{
		flag = 1;
		cin >> x >> y;
		vec.resize(x);
		for (int i = 0; i < x; i++)
			cin >> vec[i];
		for (int i = 0; i < (1 << x); i++)
		{
			ans = c = 0, j = i;
			while (j != 0)
			{
				if (j % 2 == 1)
					ans += vec[c];
				j /= 2;
				c++;
			}
			if (ans == y) {
				cout << "Yes\n", flag = 0;
				break;
			}
		}
		if (flag)
			cout << "No\n";
	}

	return 0;
}