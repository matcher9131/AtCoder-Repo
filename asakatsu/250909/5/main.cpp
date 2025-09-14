#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e18;

using S = ll;
S op(S a, S b) {
    return a + b;
}
S e() {
    return 0;
}
using F = ll;
S mapping(F f, S x) {
    return f + x;
}
F composition(F f, F g) {
    return f + g;
}
F id() {
    return 0;
}

using SegTree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    ll k = 0;
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '.') ++k;
        }
    }

    vector<SegTree> colSpan(h, SegTree(w)), rowSpan(w, SegTree(h));

    for (ll i = 0; i < h; ++i) {
        ll right = 0;
        while (right < w) {
            ll left = right;
            for (; right < w; ++right) {
                if (s[i][right] == '#') break;
            }
            colSpan[i].apply(left, right, right-left);
            ++right;
        }
    }
    for (ll j = 0; j < w; ++j) {
        ll bottom = 0;
        while (bottom < h) {
            ll top = bottom;
            for (; bottom < h; ++bottom) {
                if (s[bottom][j] == '#') break;
            }
            rowSpan[j].apply(top, bottom, bottom-top);
            ++bottom;
        }
    }

    mint ans = 0;
    mint base2 = 2;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '#') continue;
            ll c = colSpan[i].get(j) + rowSpan[j].get(i) - 1;
            ans += base2.pow(k-c) * (base2.pow(c) - 1);
        }
    }

    cout << ans.val() << endl;
    return 0;
}