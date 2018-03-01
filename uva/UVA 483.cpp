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
	bool chk;
	while (getline(cin , s))
	{
		s += " ";
		vector<bool> vis(s.length());
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
				vis[i] = 1;
		}
		t = "";
		bool f = 0;
		for (int i = 0; i < vis.size(); i++)
		{
			if (vis[i])
				t += s[i], f = 1;
			else if (f)
			{
				reverse(t.begin(), t.end());
				cout << t;
				if (i != vis.size() - 1)
					cout << " ";
				t = "";
				f = 0;
			}
		}
		cout << endl;
	}

	return 0;
}