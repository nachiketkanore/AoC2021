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

char solve(const string& s) {
    stack<char> stk;
    for (char ch : s) {
        if (is_opening(ch)) {
            stk.push(ch);
        } else {
            if (stk.empty()) {
                return ch;
            }
            if (dont_match(stk.top(), ch)) {
                return ch;
            }
            stk.pop();
        }
    }
    return 'a';
}

bool valid(char ch) {
    return ch != 'a';
}

int cost(char ch) {
    if (ch == ')') return 3;
    if (ch == ']') return 57;
    if (ch == '}') return 1197;
    if (ch == '>') return 25137;
    assert(false);
    return -1;
}

int32_t main() {
    int ans = 0;
    for (string x; cin >> x; ) {
        char get = solve(x);
        if (valid(get)) {
            cout << get << '\n';
            ans += cost(get);
        }
    }
    cout << ans << '\n';
}
