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

int main() 
{
	string s;
	int T, cnt;
	cin >> T;
	while (T--)
	{
		cin >> s;
		cnt = 0;
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(') { cnt++; }
			else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') { st.push(s[i]); }
			else if (s[i] == ')' && cnt > 1) { cout << st.top(); st.pop(); }
			else if (s[i] == ')' && cnt == 1) continue;
			else cout << s[i];
		}
		while (!st.empty()) { cout << st.top(); st.pop(); }
		cout << endl;
	}


	return 0;
}