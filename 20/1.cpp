/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 23 December 2021 07:37:55 PM IST
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

const int TIMES = 2;
string algo;
vector<string> mat, nmat;

void print() {
    static int pid = 0;
    cout << "printing " << ++pid << " times\n";
    cout << string(100, '-') << '\n';
    for (const auto &row: mat) {
        cout << row << '\n';
    }
    cout << string(100, '-') << '\n';
}

void check() {
    for (const auto row: mat) {
        assert(sz(row) == sz(mat.back()));
    }
}
void resize() {
    const int M = mat[0].size();
    mat.insert(mat.begin(), string(M, '.'));
    mat.push_back(string(M, '.'));

    for (string &row: mat) {
        row = "." + row + ".";
    }
    check();
}


void perform() {
    const int N = mat.size();
    const int M = mat[0].size();
    nmat = mat;

    F0R (i,N) {
        F0R (j,N) {
            int id = 0;
            FOR (row, i - 1, i + 1) {
                FOR (col, j - 1, j + 1) {
                    id *= 2;
                    if (row < 0 || row >= N || col < 0 || col >= M) continue;
                    else {
                        if (mat[row][col] == '#')
                            id += 1;
                    }
                }
            }
            assert(id < 512);
            nmat[i][j] = algo[id];
        }
    }

    mat = nmat;
}

int32_t main() {
    freopen("in", "r", stdin);
    cin >> algo;
    assert(sz(algo) == 512);
    for (string row; cin >> row; ) {
        mat.push_back(row);
        if (mat.size()) assert(sz(row) == sz(mat.back()));
    }
    F0R (rep, TIMES) {
        resize();
        print();
        perform();
    }
    int ans = 0;
    for (auto row: mat) {
        for (auto ch: row) ans += ch == '#';
    }
    cout << ans << '\n';
}
