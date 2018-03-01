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
int x[26];
int main()
{	
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		x[s[i] - 'a']++;
	}
	int c = 0;
	for (int i = 0; i < 26; i++)
		if (x[i] != 0)
			c++;
	if (c % 2 == 0)
		cout << "CHAT WITH HER!\n";
	else
		cout << "IGNORE HIM!\n";
	return 0;
}