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
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#define ll long long
#define ull unsigned long long 
#define ld long double
#define endl "\n"
using namespace std;
int x[26];
int main() 
{
	ios_base::sync_with_stdio(); cin.tie(NULL); cout.tie(NULL);

	string s;
	ll cnt = 0;
	cin >> s;
	for (int i = 0; i < 26; i++)
		scanf("%d", &x[i]);
	for (int i = 0; i < s.size(); i++) if (s[i] == '?') cnt++;
	if (cnt == s.size()) 
	{
		printf("0\n");
		for (int i = 0; i < s.size(); i++) printf("a");
		printf("\n");
	}
	else
	{
		int st, en;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '?')
			{
				st = i;
				en = i;
				for (int j = i + 1; j < s.size(); j++)
					if (s[j] == '?') en = j;
					else
						break;
				i = en;
				char ans;

				if (st == 0) ans = s[en + 1];
				else if (en == s.size() - 1) ans = s[st - 1];
				else
				{
					int mn1 = 100001, mn2 = (int)100001;
					for (int j = 0; j < 26; j++)
					{
						if ((mn1 + mn2) > (abs(x[s[st - 1] - 'a'] - x[j]) + abs(x[s[en + 1] - 'a'] - x[j])))
						{
							mn1 = abs(x[s[st - 1] - 'a'] - x[j]); mn2 = abs(x[s[en + 1] - 'a'] - x[j]); ans = char(j + 'a');
						}
					}
				}
				s[st] = ans;
			}	
		}
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == '?') s[i] = s[i - 1];
		}
		cnt = 0;
		for (int i = 0;  i < s.size() - 1; i++)
			cnt += abs(x[s[i] - 'a'] - x[s[i + 1] - 'a']);
		cout << cnt << endl << s << endl;
	}


	return 0;
}