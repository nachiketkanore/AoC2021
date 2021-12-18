/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 14 December 2021 12:05:34 AM IST
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

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 5005;
char mat[N][N];

void solve(string file) {
    freopen(file.c_str(), "r", stdin);

    F0R (i,N) F0R (j,N) mat[i][j] = '.';
    while (true) {
        string x;
        cin >> x;
        if (x == "end") break;
        int yc = 0, xc = 0;
        int i = 0;
        while (i < sz(x) && x[i] != ',') {
            yc = yc * 10 + (x[i] - '0');
            i++;
        }
        i++;
        while (i < sz(x)) {
            xc = xc * 10 + (x[i] - '0');
            i++;
        }
        mat[xc][yc] = '#';
    }

    auto print = [&]() {
        F0R (i,20) {
            F0R (j,150) {
                cout << mat[i][j];
            }
            cout << '\n';
        }
    };

    auto fold_left = [&](int col) {
        int col1 = col - 1, col2 = col + 1;
        F0R (row,N) mat[row][col] = '.';
        while (col1 >= 0 && col2 < N) {
            F0R (row,N) {
                if (mat[row][col1] == '#' || mat[row][col2] == '#') {
                    mat[row][col1] = '#';
                } else {
                    mat[row][col1] = '.';
                }
                mat[row][col2] = '.';
            }
            col1--;
            col2++;
        }
    };

    auto fold_up = [&](int row) {
        int row1 = row - 1, row2 = row + 1;
        F0R (col,N) mat[row][col] = '.';
        while (row1 >= 0 && row2 < N) {
            F0R (col,N) {
                if (mat[row1][col] == '#' || mat[row2][col] == '#') {
                    mat[row1][col] = '#';
                } else {
                    mat[row1][col] = '.';
                }
                mat[row2][col] = '.';
            }
            row1--;
            row2++;
        }
    };

    string x;
    while (getline(cin, x)) {
        if (sz(x) == 0) continue;
        int coord = stoll(x.substr(13));
        if (x[11] == 'x') {
            fold_left(coord);
        } else {
            fold_up(coord);
        }
        /* break; */
    }

    print();

    int ans = 0;
    F0R (i,N) F0R (j,N) {
        ans += mat[i][j] == '.';
    }
    cout << '\n' << file << '\n';
    cout << ans << '\n';
    fclose(stdin);
}

int32_t main() {
    /* solve("sample"); */
    solve("in");
    // Answer = RCPLAKHL
}
