#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <numeric>
#include <functional>
#include <atcoder/lazysegtree>
#include <compare>
using namespace std;
using ll = long long;

using S = int;
S op(S a, S b) { return a + b; }
S e() { return 0; }
struct F {
    int l;
    int r;
    int count;

    bool isID() { return l == 0 && r == 0 && count == 0; }
};
S mapping(F f, S x) {
    return f.l + f.r + (f.count % 2 ? -x - 1 : x);
}
F id() {
    return { 0, 0, 0 };
}
F composition(F f, F g) {
    if (f.isID()) return g;
    return { f.l - g.l, f.r - g.r, f.count + g.count };
}


char trans(char c) {
    if ('a' <= c && c <= 'z') {
        return c - 32;
    } else {
        return c + 32;
    }
}

int main() {
    string s;
    cin >> s;
    vector<char> ch;
    vector<int> lv;
    int currentLevel = 0;
    // lv, [l, r)
    vector<tuple<int, int, int>> segment;
    vector<int> pl;
    for (const char c : s) {
        if (c == '(') {
            ++currentLevel;
            pl.push_back(ch.size());
        } else if (c == ')') {
            segment.emplace_back(currentLevel, pl.back(), (int)ch.size());
            pl.pop_back();
            --currentLevel;
        } else {
            ch.push_back(c);
            lv.push_back(currentLevel);
        }
    }
    int n = ch.size();
    sort(segment.begin(), segment.end(), greater<tuple<int, int, int>>());

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    for (int i = 0; i < n; ++i) {
        seg.set(i, i);
    }

    for (const auto &[_, l, r] : segment) {
        seg.apply(l, r, {l, r, 1});
    }

    string ans(n, '_');
    for (int i = 0; i < n; ++i) {
        int j = seg.get(i);
        ans[j] = lv[i] % 2 ? trans(ch[i]) : ch[i];
    }
    cout << ans << endl;

    return 0;
}