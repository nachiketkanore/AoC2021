/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 07 December 2021 11:49:28 AM IST
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

int32_t main() {
    vector<int> A;
    int x;
    while (cin >> x) {
        A.push_back(x);
    }
    const int INF = 1e18;
    int answer = INF;
    for (int pos: A) {
        int required = 0;
        for (int pos2: A) {
            required += abs(pos - pos2);
        }
        cmin(answer, required);
    }
    cout << answer << '\n';
    // Answer = 364898
}
