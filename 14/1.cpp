/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 18 December 2021 02:42:59 PM IST
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

map<string, string> to;

void solve(string file) {
    freopen(file.c_str(), "r", stdin);
    string S;
    cin >> S;

    for (string u, v; cin >> u >> v; ) {
        to[u] = v;
    }

    map<string, int> cnt;

    F0R (i,sz(S)-1) {
        string u;
        u += S[i];
        u += S[i + 1];
        cnt[u]++;
    }

    auto print = [&](int step) {
        int len = 1;
        cout << "Step = " << step << " :\n";
        map<char, int> freq;
        vector<int> freqs;

        for (const auto [str, f]: cnt) {
            /* cout << str << ' ' << f << '\n'; */
            freq[str[0]] += f;
            freq[str[1]] += f;
            len += f;
        }
        for (auto it : freq) {
            char ch = it.first;
            int times = it.second;
            times /= 2;
            if (S[0] == ch) times++;
            if (S.back() == ch) times++;
            cout << ch << " " << times << '\n';
            freqs.push_back(times);
        }
        sort(ALL(freqs));
        /* for (auto x: freqs) { */
        /*     cout << x << ' '; */
        /* } cout << '\n'; */
        cout << freqs.back()  - freqs.front() << '\n';
        /* cout << "len = " << len << "\n"; */
    };

    const int STEPS = 40;
    F0R (step, STEPS) {
        print(step);

        map<string, int> ncnt;

        for (auto it: cnt) {
            string curr = it.first;
            int freq = it.second;
            assert(sz(curr) == 2);
            assert(to.count(curr));
            char becomes = to[curr][0];

            string first; first += curr[0]; first += becomes;
            string second; second += becomes; second += curr[1];

            ncnt[first] += freq;
            ncnt[second] += freq;
        }

        cnt = ncnt;

        if (step == STEPS - 1) {
            cout << "final counts after " << STEPS << " steps :\n";
            print(STEPS);
        }
    }
}

int32_t main() {
    solve("in");
    /* solve("in"); */
    // Answer = 4807056953866
}
