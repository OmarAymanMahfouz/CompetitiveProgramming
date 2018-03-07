#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define ull unsigned long long 
#define ld long double
using namespace std;
int main()
{
	vector<int> vec;
	for (int i = 0; i < 64; i++)
		vec.push_back((1 << i));
	int x, c = 0, y;
	cin >> x;
	while (x)
	{
		for (int i = 1; i < vec.size(); i++)
		{
			if (x == vec[i])
			{
				y = vec[i];
				break;
			}
			else if (x < vec[i])
			{
				y = vec[i - 1];
				break;
			}
		}
		x -= y;
		c++;
	}
	cout << c << "\n";

	return 0;
}