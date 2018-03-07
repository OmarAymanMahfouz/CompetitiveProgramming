#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define ull unsigned long long 
#define ld long double
using namespace std;
int main()
{
	vector<int>vec;
	int n;
	while (cin >> n && n)
		vec.push_back(n);
	for (int j = 0; j < vec.size(); j++)
	{
		queue<int> q;
		for (int i = 1; i <= vec[j]; i++)
			q.push(i);
		if (q.size() == 1)
			cout << "Discarded cards:";
		else
			cout << "Discarded cards: ";
		while (q.size() != 1)
		{
			if (q.size() != 2)
				cout << q.front() << ", ";
			else
				cout << q.front();
			q.pop();
			q.push(q.front());
			q.pop();
		}
		cout << "\n";
		cout << "Remaining card: " << q.front() << "\n";
	}
	return 0;
}