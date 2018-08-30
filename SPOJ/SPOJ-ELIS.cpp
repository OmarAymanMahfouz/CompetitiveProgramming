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
short x;
short y[21];
int dp[21][21];
int solution(short last = 0, short indix = 1) {
	if (indix - 1 == x)
		return 0;
	if (dp[last][indix] != -1)
		return dp[last][indix];
	short option1 = 0, option2 = 0;
	if (y[last] < y[indix])
		option1 = 1 + solution(indix, indix + 1);
	option2 = solution(last, indix + 1);
	return dp[last][indix] = max(option1, option2);
}

int main() 
{
	cin >> x;
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= x; i++)
		cin >> y[i];
	cout << solution() << endl;

	return 0;
}