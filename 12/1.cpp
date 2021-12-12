/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 12 December 2021 02:42:28 PM IST
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
#include <map>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

map<string, vector<string>> graph;

void add_edge(const string& u, const string& v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

map<string, int> vis;

bool is_small(const string &s) {
    bool yes = true;
    for (char ch: s) {
        yes &= 'a' <= ch && ch <= 'z';
    }
    return yes;
}

int go(const string &u, vector<string> path) {
    if (is_small(u) && vis[u] > 1) return 0;
    if (u == "start" && vis[u] > 1) return 0;
    if (u == "end") {
        /* for (string p: path) { */
        /*     cout << p << " -> "; */
        /* } */
        /* cout << '\n'; */
        return 1;
    }
    int ans = 0;

    for (const auto &v: graph[u]) {
        vis[v]++;
        vector<string> npath = path;
        npath.push_back(v);
        ans += go(v, npath);
        vis[v]--;
    }
    return ans;
}

int32_t main() {
    freopen("in", "r", stdin);
    for (string x; cin >> x;) {
        string u, v;
        int i = 0;
        while (i < sz(x) && x[i] != '-') {
            u += x[i];
            i++;
        }
        i++;
        while (i < sz(x)) {
            v += x[i];
            i++;
        }
        add_edge(u, v);
    }

    vector<string> path = {"start"};
    vis["start"] = 1;
    int ans = go("start", path);
    cout << ans << '\n';
    // Answer = 4691
}
