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
#include <fstream>
#define ll long long
#define ull unsigned long long 
#define ld long double
#define endl "\n"
using namespace std;
void DO_NOT_STOP()
{
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

int sum, n;
struct node
{
	int sum;
	vector<short> v;
};

vector<short> vec;
set<vector<short>> s;
void get_ans(int idx, node ans)
{
	if (idx == n) return;
	node tmp = ans;
	if (tmp.sum + vec[idx] == sum) { tmp.v.push_back(vec[idx]); tmp.sum += vec[idx]; s.insert(tmp.v); }
	else if (tmp.sum + vec[idx] < sum)
	{
		tmp.v.push_back(vec[idx]);
		tmp.sum += vec[idx];
		get_ans(idx + 1, tmp);
	}
	get_ans(idx + 1, ans);
}
void print(set<vector<short>>::iterator e)
{
	if (e == s.end()) return;
	set<vector<short>>::iterator t = e; t++;
	print(t);
	vector<short> v = *e;
	for (int i = 0; i < v.size(); i++)
	{
		if (i == v.size() - 1) cout << v[i] << endl;
		else cout << v[i] << "+";
	}
}
int main() {
	DO_NOT_STOP();
	while (cin >> sum >> n && (sum || n))
	{
		vec.resize(n);
		for (int i = 0; i < n; i++) cin >> vec[i];
		node x; x.sum = 0;
		get_ans(0, x);
		cout << "Sums of " << sum << ":\n";
		if (s.empty()) cout << "NONE\n";
		else
		{
			print(s.begin());
		}
		s.clear();
	}
}