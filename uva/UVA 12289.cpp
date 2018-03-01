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
	string s, one = "one", two = "two";
	int x;
	cin >> x;
	while (x--)
	{
		cin >> s;
		if (s.length() == 5) {
			cout << 3 << endl;
			continue;
		}
		int on[3] = { 0 }, tw[3] = { 0 };
		for (int i = 0; i < s.length(); i++)
			for (int j = 0; j < one.length(); j++)
				if (s[i] == one[j])
					on[j]++;
		for (int i = 0; i < s.length(); i++)
			for (int j = 0; j < two.length(); j++)
				if (s[i] == two[j])
					tw[j]++;
		int o = 0, t = 0;
		for (int i = 0; i < 3; i++)
		{
			if (on[i] != 0)
				o++;
			if (tw[i] != 0)
				t++;
		}
		if (o >= t)
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}

	system("pause");
	return 0;
}