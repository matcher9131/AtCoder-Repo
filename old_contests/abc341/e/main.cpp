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
using namespace std;
using ll = long long;

struct S {
    int begin;
    int end;
    bool alt;
};
S op(S a, S b) {
    if (!a.alt || !b.alt) {
        return { a.begin, b.end, false };
    } else {
        return { a.begin, b.end, a.end != b.begin || a.end == 0 || b.begin == 0 };
    }
}
S e() {
    return { 0, 0, true };
}
using F = int;
S mapping(F f, S x) {
    return {
        f % 2 ? -x.begin : x.begin,
        f % 2 ? -x.end : x.end,
        x.alt
    };
}
F composition(F f, F g) {
    return f + g;
}
F id() {
    return 0;
}

int main() {
    int n, nq;
    string s;
    cin >> n >> nq >> s;
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            seg.set(i, {1, 1, true});
        } else {
            seg.set(i, {-1, -1, true});
        }
    }

    while (nq--) {
        int k, l, r;
        cin >> k >> l >> r;
        --l;
        --r;
        if (k == 1) {
            seg.apply(l, r+1, 1);
        } else {
            bool ans = seg.prod(l, r+1).alt;
            cout << (ans ? "Yes" : "No") << endl;
        }
    }

    return 0;
}