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
int x[1000001];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	int n, h, low, high;
	cin >> T;
	while (T--)
	{
		cin >> n >> h;
		for (int i = 1; i <= n; i++) {
			cin >> low >> high;
			x[low]++;
			x[high + 1]--;
		}
		for (int i = 1; i < n; i++)
			x[i] += x[i - 1];
		for (int i = 0; i < n; i++)
			x[i] = n - x[i];
		for (int i = 1; i < n; i++)
			x[i] += x[i - 1];
		low = x[h - 1];
		for (int i = h; i < n; i++)
			low = min(low, (x[i] - x[i - h]));
		cout << low << endl;
		memset(x, 0, sizeof x);
	}
	return 0;
}