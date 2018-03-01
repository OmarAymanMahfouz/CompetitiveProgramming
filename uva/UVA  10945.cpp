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
bool palindrome(string s)
{
	string t = s;
	reverse(s.begin(), s.end());
	if (s == t)
		return 1;
	return 0;
}
int main()
{
	string s;
	while (true)
	{
		getline(cin, s);
		if (s == "DONE")
			break;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 32;
			else if (s[i] == ' ' || s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?')
				s.erase(s.begin() + i), i--;
		}
		
		if (palindrome(s))
			cout << "You won't be eaten!\n";
		else
			cout << "Uh oh..\n";
	}

	return 0;
}