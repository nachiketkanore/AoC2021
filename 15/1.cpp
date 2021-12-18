/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 18 December 2021 03:25:57 PM IST
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
#include <queue>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(string file) {
    freopen(file.c_str(), "r", stdin);
    vector<vector<int>> mat;
    for (string row; cin >> row; ) {
        vector<int> add_row;
        for (char ch : row) {
            add_row.push_back(int(ch - '0'));
        }
        cout << row << endl;
        mat.push_back(add_row);
    }

    const int N = mat.size();
    const int M = mat[0].size();
    /* cout << N << ' ' << M << endl; */

    auto node = [&](int i, int j) {
        // keep 1-based indexing
        assert(0 <= i && i < N && 0 <= j && j < M);
        /* cout << i << ' ' << j << endl; */
        i++, j++;
        return (i - 1) * M + j;
    };

    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};
    vector<vector<pair<int,int>>> g(N * M + 1);
    vector<int> d(N * M + 1, 1e9);

    // creating graph
    F0R (i,N) {
        F0R (j,M) {
            int u = node(i, j);
            F0R (id, 4) {
                int ni = i + dx[id];
                int nj = j + dy[id];
                if (0 <= ni && ni < N && 0 <= nj && nj < M) {
                    int v = node(ni, nj);
                    g[u].push_back({v, mat[ni][nj]});
                }
            }
        }
    }

    auto dijkstra = [&](int s) {

        d[s] = 0;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});
        while (!q.empty()) {
            int v = q.top().second;
            int d_v = q.top().first;
            q.pop();
            if (d_v != d[v])
                continue;

            for (auto edge : g[v]) {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    q.push({d[to], to});
                }
            }
        }
    };

    dijkstra(node(0, 0));

    cout << d[node(N-1, M-1)] << '\n';
}

int32_t main() {
    solve("sample");
    /* solve("in"); */
    /* solve("check"); */
}
