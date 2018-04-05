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
	int n, x, cnt;
	while (cin >> n && n)
	{
		while (cin >> x && x)
		{
			vector<int> vec(n);
			stack<int> st;
			cnt = 0;
			vec[0] = x;
			for (int i = 1; i < n; i++)
				cin >> vec[i];
			for (int i = 1; i <= n; i++)
			{
				st.push(i);
				while (!st.empty() && st.top() == vec[cnt])
				{
					st.pop(), cnt++;
					if (n <= cnt)
						break;
				}
			}
			cout << ((st.empty()) ? "Yes\n" : "No\n");
		}
		cout << endl;
	}

	return 0;
}