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
	int cups = 0, med = 0, x, ans = 0;
	for (int i = 0; i < 3; i++)
		cin >> x, cups += x;
	for (int i = 0; i < 3; i++)
		cin >> x, med += x;
	cin >> x;
	ans += (cups / 5);
	if (cups % 5 != 0)
		ans++;
	ans += (med / 10);
	if (med % 10 != 0)
		ans++;
	(ans <= x) ? cout << "YES\n" : cout << "NO\n";

	return 0;
}