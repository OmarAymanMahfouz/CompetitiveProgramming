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
int vec[1001], vec1[1001];
ll n;

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
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	mergesort(0, n - 1);
	bool f = 1;
	for (int i = 0, j = n - 1; i <= j;) {
		if (f) cout << vec[i++] << " ";
		else cout << vec[j--] << " ";
		f = !f;
	}
	cout << "\n";

	system("pause");
	return 0;
}