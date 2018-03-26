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
	map<string, string> mp;
	map<string, string> ::iterator it;
	int T;
	string s, r, t;
	bool f, one, two, three;
	set<pair<string, string>> st;
	pair<string, string> p;
	cin >> T;
	while (T--)
	{
		one = two = three = 0;
		cin >> s;
		r = t = "";
		f = 0;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == '{')continue;
			else if (s[i] == '}') mp[r] = t, t = "", r = "", f = 0;
			else if (s[i] == ',') mp[r] = t, t = "", r = "", f = 0;
			else if (s[i] == ':') f = 1;
			else if (s[i] != ':' && f) t += s[i];
			else if (s[i] != ':' && !f) r += s[i];
		
		cin >> s;
		t = r = "";
		int cnt = 0, c = 0;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == '{') continue;
			else if (s[i] == '}' || s[i] == ',')
			{
				p.first = r, p.second = t;
				st.insert(p);
				r = t = "";
				f = 0;
			}
			else if (s[i] == ':') f = 1;
			else if (s[i] != ':' && f) t += s[i];
			else if (s[i] != ':' && !f) r += s[i];
		bool f;
		s = "";
		for (auto e : st)
		{
			f = 1;
			for (it = mp.begin(); it != mp.end(); it++)
			{
				if (e.first == it->first)
				{
					f = 0;
					break;
				}
			}
			if (f)
			{
				one = 1;
				if (cnt++ == 0) s+='+' + e.first;
				else s+=e.first;
				s += ',';
				
			}
		}
		if (s.size() > 2)
			s.pop_back(), cout << s << endl;
		cnt = 0;
		s = "";
		for (it = mp.begin(); it != mp.end(); it++)
		{
			
			f = 1;
			for (auto e : st)
			{
				if (it->first == e.first)
				{
					f = 0;
					break;
				}
			}
			if (f)
			{
				two = 1;
				if (cnt++ == 0) s += '-' + it->first;
				else s += it->first;
				s += ',';
			}
		}
		if (s.size() > 2)
			s.pop_back(), cout << s << endl;
		cnt = 0;
		s = "";
		for (auto e : st)
		{
			for (it = mp.begin(); it != mp.end(); it++)
			{
				if (e.first == it->first)
				{
					if (e.second != it->second)
					{
						three = 1;
						if (cnt++ == 0) s += '*' + it->first;
						else s += it->first;
						s += ',';
					}
					break;
				}
			}
		}
		
		if (s.size() > 2)
			s.pop_back(), cout << s << endl;

		if (!one && !two && !three)
			cout << "No changes\n";
		mp.clear();
		st.clear();
		cout << endl;
	}
	system("pause");
	return 0;
}