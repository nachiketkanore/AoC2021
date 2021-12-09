/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 09 December 2021 04:08:40 PM IST
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
#include <functional>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int32_t main() {
    vector<vector<int>> mat;
    string x;
    while (cin >> x) {
        vector<int> row;
        for (char ch : x) {
            row.push_back(int(ch-'0'));
        }
        mat.push_back(row);
    }
    const int N = mat.size();
    const int M = mat[0].size();

    // Count basins: connected component surrounded by 9 or it is just a boundary cell

    vector<vector<bool>> vis(N, vector<bool>(M, false));
    F0R (i,N) {
        F0R (j,M) {
            if (mat[i][j] == 9) vis[i][j] = true;
        }
    }

    vector<int> sizes;
    int curr_size = 0;

    auto inside = [&](int i, int j) {
        return 0 <= i && i < N && 0 <= j && j < M;
    };

    function<void(int, int)> dfs = [&](int i, int j) {
        if (!inside(i, j)) return;
        if (vis[i][j]) return;
        vis[i][j] = true;
        curr_size++;
        F0R (id, 4) {
            dfs(i + dx[id], j + dy[id]);
        }
    };

    F0R (i,N) {
        F0R (j,M) {
            if (vis[i][j]) continue;
            curr_size = 0;
            dfs(i, j);
            sizes.push_back(curr_size);
        }
    }
    sort(ALL(sizes));
    reverse(ALL(sizes));
    cout << sizes[0] * sizes[1] * sizes[2] << '\n';
    // Answer = 1397760
}
