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
int n[100001], ans[100001];
bool chk[100001];
int main()
{	
	int x, y;
	cin >> x >> y;
	for (int i = 1; i <= x; i++)
		cin >> n[i];
	int counter = 0;
	for (int i = x; i > 0; i--)
	{
		if (chk[n[i]] == 0)
		{
			counter++;
			ans[i] = counter;
			chk[n[i]] = 1;
		}
		else
			ans[i] = counter;
	}
	while (y--)
	{
		int a;
		cin >> a;
		cout << ans[a] << endl;
	}
	

	system("pause");
	return 0;
}