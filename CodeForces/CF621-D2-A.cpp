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
ll x[100001];
int main()
{
	int n;
	int f = 1e9;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		if (x[i] < f && x[i] % 2 != 0)
			f = x[i];
	}
	for (int i = 1; i <= n; i++)
		x[i] += x[i - 1];
	ll ans = x[n] - f;
	for (int i = n; i > 0; i--)
	{
		if (x[i] % 2 == 0)
		{
			ans = max(ans, x[i]);
		}
	}
	cout << ans << endl;
	return 0;
}