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
#include <unordered_map>
#include <unordered_set>
#define ll long long
#define ull unsigned long long 
#define ld long double
using namespace std;

int main()
{
	int n;
	while (cin >> n && n)
	{
		bitset<31> x(n), y, z;
		int ind = 0;
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] == 1)
			{
				ind++;
				if (ind & 1) y[i] = 1, z[i] = 0;
				else y[i] = 0, z[i] = 1;
			}
			else
				y[i] = z[i] = 0;
		}
		cout << y.to_ulong() << " " << z.to_ulong() << endl;
	}
	
	return 0;
}