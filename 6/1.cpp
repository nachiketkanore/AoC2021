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

int DAYS = 80;

// 6 8 1 1 3 0 2 2 4 6 8 1 1 3 4 6 6 8 6 8 1 5 7 0 0 2
// 6 0 6 4 5 6 0 1 1 2 6 0 1 1 1 2 2 3 3 4 6 7 8 8 8 8

int32_t main() {
	vector<int> A;
	int x;
	while (cin >> x) {
		A.push_back(x);
	}
	FOR (day, 1, DAYS) {
		vector<int> nA;
		for (int x: A) {
			if (x == 0) {
				nA.push_back(6);
				nA.push_back(8);
			} else {
				nA.push_back(x - 1);
			}
		}
		A = nA;
	}
	cout << sz(A) << '\n';
	// Answer = 379114
}
