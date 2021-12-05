/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 05 December 2021 11:26:12 AM IST
**/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

template <class T>
bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int MAX = 5e3;
int cnt[MAX][MAX];

int32_t main()
{
	int x1, y1, x2, y2;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);
		assert(x1 < MAX && y1 < MAX && x2 < MAX && y2 < MAX);
		if (x1 == x2) {
			FOR(y, y1, y2)
			{
				cnt[x1][y]++;
			}
		} else if (y1 == y2) {
			FOR(x, x1, x2)
			{
				cnt[x][y1]++;
			}
		}
	}
	int answer = 0;
	F0R(i, MAX)
	{
		F0R(j, MAX)
		{
			if (cnt[i][j] >= 2) {
				++answer;
			}
		}
	}
	cout << answer << '\n';
	// Answer = 5698
	cout << "OK\n";
}
