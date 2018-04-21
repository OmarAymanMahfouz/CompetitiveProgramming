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
void fill()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
struct node {
	vector<ll>vec;
	ll sum = 0;
};
int x, y;
vector<ll> v(21);
bool operator < (node a, node b)
{
	if (a.sum != b.sum)return a.sum > b.sum;
	return a.vec.size()> b.vec.size();
}
node solve(node ans, int idx)
{
	if (idx == y)return ans;
	node option1 = solve(ans, idx + 1);
	node option2;
	if (ans.sum + v[idx] <= x)
	{
		ans.sum += v[idx];
		ans.vec.push_back(v[idx]);
		option2 = solve(ans, idx + 1);
	}
	return min(option1, option2);
}
int main() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	fill();
	while (cin >> x >> y)
	{
		for (int i = 0; i < y; i++)
			cin >> v[i];
		node temp;
		temp.sum = 0;
		node ans = solve(temp, 0);
		for (int i = 0; i < ans.vec.size(); i++)
			cout << ans.vec[i] << " ";
		cout << "sum:" << ans.sum << endl;
	}
	return 0;
}