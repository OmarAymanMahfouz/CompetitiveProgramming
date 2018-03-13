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
	multiset<int> ms;
	int n, x;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
			cin >> x, ms.insert(x);
		multiset<int>::iterator it, i;
		it = ms.begin();
		i = ms.begin(), i++;
		ll res = 0;
		while (ms.size() > 1)
		{
			ms.insert(*i + *it);
			res += *i + *it;
			ms.erase(ms.begin());
			ms.erase(ms.begin());
			it = ms.begin();
			i = ms.begin(), i++;
		}
		cout << res << "\n";
		ms.clear();
	}

	
	return 0;
}