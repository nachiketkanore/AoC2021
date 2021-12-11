/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 11 December 2021 11:37:37 AM IST
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
#include <stack>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

bool is_opening(char ch) {
    return ch == '(' || ch == '{' || ch == '[' || ch == '<';
}

bool dont_match(char one, char two) {
    if (one == '(' && two == ')') return false;
    if (one == '[' && two == ']') return false;
    if (one == '{' && two == '}') return false;
    if (one == '<' && two == '>') return false;
    return true;
}

stack<char> solve(const string& s) {
    stack<char> stk, ret;
    for (char ch : s) {
        if (is_opening(ch)) {
            stk.push(ch);
        } else {
            if (stk.empty()) {
                return ret;
            }
            if (dont_match(stk.top(), ch)) {
                return ret;
            }
            stk.pop();
        }
    }
    /* cout << s << ' '; */
    /* while (!stk.empty()) { */
    /*     cout << stk.top(); */
    /*     stk.pop(); */
    /* } */
    /* cout << '\n'; */
    return stk;
}

int get_cost(char ch) {
    if (ch == '(') return 1;
    if (ch == '[') return 2;
    if (ch == '{') return 3;
    if (ch == '<') return 4;
    assert(false);
    return -1e9;
}

int32_t main() {
    /* freopen("sample", "r", stdin); */
    freopen("in", "r", stdin);
    vector<int> scores;
    for (string x; cin >> x; ) {
        stack<char> get = solve(x);
        if (get.empty()) continue;
        int score = 0;
        while (!get.empty()) {
            score = score * 5 + get_cost(get.top());
            get.pop();
        }
        /* cout << score << '\n'; */
        scores.push_back(score);
    }
    sort(ALL(scores));
    const int N = scores.size();
    assert(N % 2 == 1);
    cout << scores[N / 2] << '\n';
    // Answer = 2776842859
}
