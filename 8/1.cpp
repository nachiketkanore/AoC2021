/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 08 December 2021 12:12:54 PM IST
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

bool all_unique(string u) {
    sort(ALL(u));
    F0R (i,sz(u)-1) {
        if (u[i] == u[i + 1])
            return false;
    }
    return true;
}

int32_t main() {
    // sample = 10, test = 200
    const int lines = 200;
    int answer = 0;
    FOR (line, 1, lines) {
        vector<string> A, B;
        F0R (i,10) {
            string u; cin >> u;
            A.push_back(u);
        }
        F0R (i,4) {
            string u; cin >> u;
            B.push_back(u);
            assert(all_unique(u));
            if (sz(u) == 2 || sz(u) == 4 || sz(u) == 3 || sz(u) == 7) {
                ++answer;
            }
        }
    }
    cout << answer << '\n';
    // Answer (part 1) = 521
}
