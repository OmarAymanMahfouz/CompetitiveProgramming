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
	int n, mx;
	vector<int> vec, vec2;
	while (cin >> n)
	{
		vec.resize(1 << n);
		vec2.resize(1 << n);
		for (int i = 0; i < (1 << n); i++)
			cin >> vec[i];
		for (int i = 0; i < (1 << n); i++)   //  (000)2 ==> (001)2, (010)2, (100)2   /  (001)2 ==> (000)2, (011)2, (101)2
			for (int j = 0; j < n; j++)
				vec2[i] += vec[i ^ (1 << j)];
	
		mx = -1e9;
		for (int i = 0; i < (1 << n); i++)
			for (int j = 0; j < n; j++)
				mx = max(mx, (vec2[i ^ (1 << j)] + vec2[i]));
		
		cout << mx << endl;
		vec.clear();
		vec2.clear();
	}

	return 0;
}