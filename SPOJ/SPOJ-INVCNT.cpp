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
vector<int>vec, vec1;
ll c, n;

void merge(int start, int mid, int end)
{
	for (int i = start; i <= end; i++)
		vec1[i] = vec[i];

	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end)
	{
		if (vec1[i] <= vec1[j])
			vec[k++] = vec1[i++];
		else {
			c += j - k;
			vec[k++] = vec1[j++];
		}
	}

	while (i <= mid) vec[k++] = vec1[i++];
}

void mergesort(int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = (start + end) / 2;
		mergesort(start, mid);
		mergesort(mid + 1, end);
		merge(start, mid, end);
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		vec1.resize(n);
		vec.resize(n);
		c = 0;
		for (int i = 0; i < n; i++)
			cin >> vec[i];
		mergesort(0, n - 1);
		cout << c << endl;
	}
	return 0;
}