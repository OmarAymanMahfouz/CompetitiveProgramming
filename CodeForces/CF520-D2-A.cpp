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
char y[100];
int x[26];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> y[i];
	for (int i = 0; i < n; i++)
		if (y[i] >= 'a')
			x[y[i] - 'a']++;
		else
			x[y[i] - 'A']++;
	for (int i = 0; i < 26; i++)
		if (x[i] < 1)
			return cout << "NO\n" , 0;
	cout << "YES\n";
	return 0;
}