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
	int n, Q;
	scanf("%d", &n);
	vector<int>vec(n);

	for (int i = 0; i < n; i++) 
		scanf("%d", &vec[i]);
	
	scanf("%d", &Q);
	while (Q--)
	{
		int x;
		cin >> x;
		int lower = (lower_bound(vec.begin(), vec.end(), x) - vec.begin()) - 1;
		if (lower < 0)
			printf("X ");
		else
			printf("%d ", vec[lower]);
		
		int upper = (upper_bound(vec.begin(), vec.end(), x) - vec.begin());
		if (upper == n) printf("X\n");
		else printf("%d\n", vec[upper]);
	}
	return 0;
}