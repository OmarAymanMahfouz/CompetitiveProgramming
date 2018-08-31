#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <queue>
#include <locale>
#include <deque>
#include <stack>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#define ll long long
#define ull unsigned long long 
#define ld long double
#define endl "\n"
using namespace std;
void DO_NOT_STOP()
{
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

char x[int(1e4 + 5) * 2];
int main() {
	DO_NOT_STOP();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", &x);
		int n = strlen(x);
		for (int i = 0; i < n; i++)
		{
			x[n + i] = x[i];
		}
		x[n + n] = '\0';
		int ans = 0;
		for (int i = 1; i < n; i++)
		{
			int flag = strncmp(x + ans, x + i, n);
			if (flag > 0)
				ans = i;
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}