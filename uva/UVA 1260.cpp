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
	int T, n;
	vector<int> vec;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		vec.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &vec[i]);
		int ans = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = i - 1; j >= 0; j--)
				if (vec[i] >= vec[j])
					ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}