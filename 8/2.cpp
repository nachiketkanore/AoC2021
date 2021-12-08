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

vector<vector<int>> pos(10);

void preprocess() {
    pos[0] = {0, 1, 2, 4, 5, 6};
    pos[1] = {2, 5};
    pos[2] = {0, 2, 3, 4, 6};
    pos[3] = {0, 2, 3, 5, 6};
    pos[4] = {1, 2, 3, 5};
    pos[5] = {0, 1, 3, 5, 6};
    pos[6] = {0, 1, 3, 4, 5, 6};
    pos[7] = {0, 2, 5};
    pos[8] = {0, 1, 2, 3, 4, 5, 6};
    pos[9] = {0, 1, 2, 3, 5, 6};
}

int solve(vector<string> A, vector<string> B) {
    assert(sz(A) == 10 && sz(B) == 4);
    string order = "abcdefg"; sort(ALL(order));
    int ret = 0;

    do {
        bool correct = true;
        vector<string> where(10);
        F0R (dig, 10) {
            for (int id: pos[dig]) {
                where[dig].push_back(order[id]);
            }
            sort(ALL(where[dig]));
            /* if (order == "deafgbc") { */
            /*     cout << dig << ' ' << where[dig] << '\n'; */
            /* } */
        }
        for (const string &a : A) {
            bool any = false;
            for (string dig: where) {
                any |= a == dig;
            }
            correct &= any;
            /* if (order == "deafgbc") { */
            /*     cout << a << " " << any << '\n'; */
            /* } */
        }
        if (correct) {
            int num = 0;
            for (const string &output: B) {
                int which = -1;
                F0R (dig, 10) {
                    if (where[dig] == output) {
                        which = dig;
                    }
                }
                assert(~which);
                num = num * 10 + which;
            }
            ret += num;
            break;
        }
    } while (next_permutation(ALL(order)));
    cout << ret << '\n';
    return ret;
}

int32_t main() {
    preprocess();
    // sample = 10, test = 200
    /* const int lines = 1; */
    /* freopen("test", "r", stdin); */
    /* const int lines = 10; */
    /* freopen("sample", "r", stdin); */
    const int lines = 200;
    freopen("in", "r", stdin);
    int answer = 0;
    FOR (line, 1, lines) {
        vector<string> A, B;
        F0R (i,10) {
            string u; cin >> u;
            sort(ALL(u));
            A.push_back(u);
        }
        F0R (i,4) {
            string u; cin >> u;
            sort(ALL(u));
            B.push_back(u);
        }
        /* for (auto it: A) { cout << it << ' '; } cout << endl; */
        /* for (auto it: B) { cout << it << ' '; } cout << endl; */
        answer += solve(A, B);
    }
    cout << answer << '\n';
    /* Answer (Finally) = 1016804 */
}
