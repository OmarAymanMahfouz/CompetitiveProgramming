#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <queue>
#include <locale>
#include <deque>
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
struct trienode
{
	trienode *children[26];
	int count[26];
} *root;

trienode* createnode()
{
	trienode *node = new trienode;
	for (int i = 0; i < 26; i++)
		node->children[i] = NULL, node->count[i] = 0;
	return node;
}
void insert(string s, trienode *cur = root)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (cur->children[s[i] - 'a'] == NULL)
		{
			cur->children[s[i] - 'a'] = createnode();
		}
		cur->count[s[i] - 'a']++;
		cur = cur->children[s[i] - 'a'];
	}
}

int search(string s, trienode *cur = root)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (cur->children[s[i] - 'a'] == NULL) return 0;
		if (i == s.size() - 1 && cur->children[s[i] - 'a'] != NULL) return cur->count[s[i] - 'a'];
		cur = cur->children[s[i] - 'a'];
	}
	return 0;
}

char x[int(1e6 + 5)];
int main() {
	DO_NOT_STOP();
	root = createnode();
	ll n, m;
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &x);
		insert(x);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%s", &x);
		printf("%d\n", search(x));
	}

	return 0;
}