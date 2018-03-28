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
map<string, int> mp;
void solve()
{
	int cnt = 1;
	for (int i = 0; i < 26; i++)
	{
		string s; s = char(i + 'a');
		mp[s] = cnt++;
	}
	for (int i = 0; i < 26; i++)
	{
		string s; s = char(i + 'a');
		for (int j = i + 1; j < 26; j++)
		{
			string t = s; t += char(j + 'a');
			mp[t] = cnt++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		string s; s = char(i + 'a');
		for (int j = i + 1; j < 26; j++)
		{
			string t = s; t += char(j + 'a');
			for (int k = j + 1; k < 26; k++)
			{
				string r = t; r += char(k + 'a');
				mp[r] = cnt++;
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		string s; s = char(i + 'a');
		for (int j = i + 1; j < 26; j++)
		{
			string t = s; t += char(j + 'a');
			for (int k = j + 1; k < 26; k++)
			{
				string r = t; r += char(k + 'a');
				for (int l = k + 1; l < 26; l++)
				{
					string st = r; st += char(l + 'a');
					mp[st] = cnt++;
				}
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		string s; s = char(i + 'a');
		for (int j = i + 1; j < 26; j++)
		{
			string t = s; t += char(j + 'a');
			for (int k = j + 1; k < 26; k++)
			{
				string r = t; r += char(k + 'a');
				for (int l = k + 1; l < 26; l++)
				{
					string st = r; st += char(l + 'a');
					for (int m = l + 1; m < 26; m++)
					{
						string tt = st; tt += char(m + 'a');
						mp[tt] = cnt++;
					}
				}
			}
		}
	}

}
int main()
{
	solve();
	string s;
	while (cin >> s)
	{
		cout << mp[s] << "\n";
	}
	
	return 0;
}