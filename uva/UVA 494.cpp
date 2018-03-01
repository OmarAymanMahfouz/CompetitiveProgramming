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
	int counter;
	while (getline(cin, s))
	{
		counter = 0;
		vector<bool> vis(s.length());
		for (int i = 0; i < s.length(); i++)
		{
			if ((s[i] >= 'A'&& s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
				vis[i] = 1;
		}
		bool f = 0;
		for (int i = 0; i < vis.size(); i++)
			if (vis[i])
			{
				f = 1;
			}
			else if (f)
			{
				counter++;
				f = 0;
			}
		cout << counter << endl;
	}

	return 0;
}