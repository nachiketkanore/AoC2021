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

    int answer = 0;
    F0R (i,N) {
        F0R (j,M) {
            int smallest = 1e9;
            F0R (id,4) {
                int ni = i + dx[id];
                int nj = j + dy[id];
                if (0 <= ni && ni < N && 0 <= nj && nj < M) {
                    cmin(smallest, mat[ni][nj]);
                }
            }
            if (mat[i][j] < smallest) {
                answer += mat[i][j] + 1;
            }
        }
    }
    cout << answer << '\n';
    // Answer = 462
}
