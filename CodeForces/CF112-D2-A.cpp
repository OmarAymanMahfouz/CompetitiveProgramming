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
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] <= 'Z')
			s[i] += 32;
		if (t[i] <= 'Z')
			t[i] += 32;
	}
	if (s > t)
		cout << 1 << endl;
	else if (s < t)
		cout << -1 << endl;
	else
		cout << 0 << endl;
	
	return 0;
}