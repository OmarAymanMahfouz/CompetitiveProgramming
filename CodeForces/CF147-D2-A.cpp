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
	string s;
	getline(cin, s);
	
	for (int i = 0; i < s.length(); i++)
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || s[i] == '.' || s[i] == '!' || s[i] == '?' || s[i] == ',')
		{
			s.erase(0, i);
			break;
		}
	for(int i = s.length() - 1; i >= 0; i--)
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || s[i] == '.' || s[i] == '!' || s[i] == '?' || s[i] == ',')
		{
			s.erase(i + 1, s.length());
			break;
		}
	for (int i = 0; i < s.length(); i++)
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			s.erase(s.begin() + i);
			i--;
		}
	for(int i = 0; i < s.length(); i++)
		if (s[i] == '!' || s[i] == ',' || s[i] == '?' || s[i] == '.')
		{
			if (i != 0)
			{
				if (s[i + 1] != ' ')
					s.insert(s.begin() + i + 1, ' ');
				if (s[i - 1] == ' ')
					s.erase(s.begin() + i - 1);
			}
			else
			{
				if (s[i + 1] != ' ')
					s.insert(s.begin() + i + 1, ' ');
			}
		}

	cout << s << endl;

	system("pause");
	return 0;
}