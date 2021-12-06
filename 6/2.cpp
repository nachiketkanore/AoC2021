/**
 *    Author: Nachiket Kanore
 *    Created: Monday 06 December 2021 10:47:35 AM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

int solve(bool sample = true, int DAYS = 0) {
	int cnt[10]; F0R (i,10) cnt[i] = 0;
	if (sample) {
		cnt[1] = 1;
		cnt[2] = 1;
		cnt[3] = 2;
		cnt[4] = 1;
	} else {
		for (int x; cin >> x;) {
			cnt[x]++;
		}
	}

	FOR (day, 1, DAYS) {
		int ncnt[10]; F0R (i,10) ncnt[i] = 0;
		F0R (x, 10) {
			if (cnt[x] == 0) continue;
			if (x == 0) {
				ncnt[6] += cnt[0];
				ncnt[8] += cnt[0];
				cnt[0] = 0;
			} else {
				ncnt[x - 1] += cnt[x];
				cnt[x] = 0;
			}
		}
		F0R (i,10) cnt[i] = ncnt[i];
	}
	int ans = 0;
	F0R (i,10) {
		ans += cnt[i];
	}
	return ans;
}

int32_t main() {
	cout << "Sample answer = " << solve(true, 256) << '\n';
	cout << "Testcase answer = " << solve(false, 256) << '\n';
}
