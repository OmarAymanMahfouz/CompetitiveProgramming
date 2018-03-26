#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define ll long long
#define ull unsigned long long 
#define ld long double
using namespace std;

int main()
{
	string s, t, ans;
	bool f;
	while (cin >> s)
	{
		t = ans = "";
		f1 = f = 0;
		for (int i = 0; i < (int)s.size(); i++)
			if (s[i] == '[' && !f) f = 1;
			else if (s[i] == '[' && f) ans.insert(0, t), t = "";
			else if (s[i] == ']' && f) ans.insert(0, t), t = "", f = 0;
			else if (s[i] != ']' && s[i] != '[' && f) t += s[i];
			else if (s[i] != ']' && s[i] != '[' && !f) ans += s[i];

			if (f)
				ans.insert(0, t);
			else
				ans += t;
			cout << ans << endl;
	}
	
	return 0;
}