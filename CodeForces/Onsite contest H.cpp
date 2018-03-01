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
int x[100001];
int y[100001];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	int q;
	cin >> q;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		y[b + 1] += -1;
		y[a] += 1;
	}
	for (int i = 1; i <= n; i++)
		y[i] += y[i - 1];
	int counter = 0;
	for (int i = 1; i <= n; i++)
		if (y[i] == 0)
			counter++;
	cout << counter << endl;
	for (int i = 1; i <= n; i++)
		if (y[i] == 0)
			cout << x[i] << " ";
	cout << endl;
	return 0;
}