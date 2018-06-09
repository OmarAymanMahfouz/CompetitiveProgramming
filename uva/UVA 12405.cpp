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
char arr[101];
int main() {
	DO_NOT_STOP();
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		int n, ans = 0; cin >> n;
		fill(arr, arr + 100, '#');
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < 99; i++)
		{
			if (arr[i] == '.' && arr[i + 1] == '.' && arr[i + 2] == '.') ans++, i += 2;
			else if (arr[i] == '.' && arr[i + 1] == '.') ans++, i += 2;
			else if (arr[i] == '.' && arr[i + 2] == '.') ans++, i += 2;
			else if (arr[i] == '.') ans++, i += 2;
		}
		cout << "Case " << k << ": "<< ans << endl;
	}
	return 0;
}