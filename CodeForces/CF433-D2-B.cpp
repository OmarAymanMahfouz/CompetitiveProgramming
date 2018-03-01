#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <iomanip>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
ll n[100001], n2[100001];
int main()
{
	int x;
	cin >> x;
	for (int i = 1; i <= x; i++)
		cin >> n[i], n2[i] = n[i];
	sort(n2, n2 + x + 1);
	for (int i = 1; i <= x; i++)
		n[i] += n[i - 1], n2[i] += n2[i - 1];

	int q;
	cin >> q;
	while (q--)
	{
		int chk, x, y;
		cin >> chk >> x >> y;
		switch (chk)
		{
		case 1: { cout << n[y] - n[x - 1] << endl; break; }
		case 2: { cout << n2[y] - n2[x - 1] << endl; break; }
		}
	}

	//system("pause");
	return 0;
}