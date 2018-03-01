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
	ll n, x;
	set <int> s;
	cin >> n >> x;
	if (n * n < x)
		cout << 0 << endl;
	else
	{
		for (ll i = 1; i * i <= x; i++)
			if (x % i == 0)
				s.insert(i), s.insert(x / i);
		set<int> ::iterator it = s.begin();
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (*it == i && (x / *it <= n))
			{
				ans++;
			}
			if (*it == i && it != s.end())
				it++;
		}
		cout << ans << endl;
	}

	return 0;
}