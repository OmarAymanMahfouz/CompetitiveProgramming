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
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int n;
	while (cin >> n)
	{
		int x, y;
		queue<int>q;
		stack<int>stk;
		priority_queue<int> pq;
		bool qu = 1, st = 1, p = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			if (x == 1)
			{
				q.push(y);
				stk.push(y);
				pq.push(y);
			}
			else
			{
				if (qu)
				{
					if (!q.empty() && q.front() == y) { q.pop(); }
					else { qu = 0; }
				}
				if (st)
				{
					if (!stk.empty() && stk.top() == y) { stk.pop(); }
					else { st = 0; }
				}
				if (p)
				{
					if (!pq.empty() && pq.top() == y) { pq.pop(); }
					else { p = 0; }
				}
			}
		}
		if (!p && !st && !qu)
			cout << "impossible" << endl;
		else if ((p && st) || (st && qu) || (qu && p))
			cout << "not sure" << endl;
		else if (qu)
			cout << "queue" << endl;
		else if (st)
			cout << "stack" << endl;
		else if (p)
			cout << "priority queue" << endl;
	}

	return 0;
}