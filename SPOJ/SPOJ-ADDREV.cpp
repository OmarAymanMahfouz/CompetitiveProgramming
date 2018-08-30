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
int solve(int n)
{
	int x = 0;
	while (n)
	{
		x *= 10;
		x += n % 10;
		n /= 10;
	}
	return x;
}
int main()
{
		
	int T, x, y, a, b;
	cin >> T;
	while (T--)
	{
		cin >> x >> y;
		a = solve(x);
		b = solve(y);
		cout << solve(a + b) << endl;
	}

	return 0;
}