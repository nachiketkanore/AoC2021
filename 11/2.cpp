/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 11 December 2021 12:15:57 PM IST
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

void print(const vector<vector<int>> &mat) {
    cout << '\n';
    for (auto row: mat) {
        for (int e: row) {
            cout << e << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

const int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int perform(vector<vector<int>> &mat) {
    const int N = mat.size();
    const int M = mat[0].size();
    bool flashed[N][M];
    memset(flashed, false, sizeof(flashed));

    for (auto &row: mat) for (auto &e: row) e++;

    while (true) {
        vector<pair<int,int>> pos;
        F0R (i,N) {
            F0R (j,M) {
                if (mat[i][j] > 9 && !flashed[i][j]) {
                    pos.push_back(make_pair(i, j));
                }
            }
        }
        if (pos.empty()) break;
        for (auto &[x, y]: pos) {
            mat[x][y] = 0;
            flashed[x][y] = true;
            F0R (id,8) {
                int nx = x + dx[id];
                int ny = y + dy[id];
                if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                    if (!flashed[nx][ny]) {
                        mat[nx][ny]++;
                    }
                }
            }
        }
    }
    int tot = 0;
    F0R (i,N) F0R (j,M) tot += flashed[i][j];
    return tot;
}

int32_t main() {
    freopen("in", "r", stdin);
    vector<vector<int>> mat;
    for (string x; cin >> x; ) {
        vector<int> row;
        for (char ch: x) {
            row.push_back(int(ch - '0'));
        }
        mat.push_back(row);
    }

    int answer = 0;
    F0R (step, 2000) {
        answer += perform(mat);
        bool all = true;
        F0R (i,sz(mat)) F0R (j,sz(mat[0])) all &= mat[i][j] == 0;
        if (all) {
            cout << "Answer = ";
            cout << 1 + step << '\n';
            break;
        }
    }
    // Answer = 222
}
