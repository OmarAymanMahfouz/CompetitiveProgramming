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
	int x, Q, cnt = 1;
	while (scanf("%d%d", &x, &Q) && (x || Q))
	{
		vector<int> vec(x);
		for (int i = 0; i < x; i++)
			cin >> vec[i];
		sort(vec.begin(), vec.end());
		printf("CASE# %d:\n", cnt++);
		while (Q--)
		{
			int a;
			cin >> a;
			int ans = lower_bound(vec.begin(), vec.end(), a) - vec.begin();
			if (ans == x || vec[ans] != a) printf("%d not found\n", a);
			else printf("%d found at %d\n", a, ans + 1);
		}
	}
	return 0;
}