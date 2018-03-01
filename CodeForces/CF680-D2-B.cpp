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
int n[101];
int main()
{	
	int a, b, ans = 0;
	cin >> a >> b;
	for (int i = 1; i <= a; i++)
		cin >> n[i], ans += n[i];
	int r = b, l = b;
	while ((--r >= 1) && (++l <= a))
	{
		if (n[r] != n[l])
			ans -= 1;
	}
	cout << ans << endl;
	return 0;
}