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
bool solve(int i, int j, int k, int C)
{
	i *= i;
	j *= j;
	k *= k;
	if (i + j + k == C)
		return 1;
	return 0;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int A, B, C;
		cin >> A >> B >> C;
		int k;
		bool flag = 0;
		for (int i = -100; i <= 100; i++)
		{
			for (int j = -100; j <= 100; j++)
			{
				for (int k = -100; k <= 100; k++)
				{
					if (i + j + k == A && i*j*k == B && solve(i, j, k, C))
						cout << i << " " << j << " " << k << "\n", flag = 1;
					if (flag)
						break;
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		if (!flag)
			cout << "No solution.\n";
	}

	return 0;
}