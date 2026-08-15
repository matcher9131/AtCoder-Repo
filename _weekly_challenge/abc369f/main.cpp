#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

struct S {
    ll value;
    ll index;
};
S op(S a, S b) {
    if (a.value > b.value) return a;
    if (a.value < b.value) return b;
    return (a.index < b.index) ? a : b; 
}
S e() {
    return {0, -1};
}
using SegTree = atcoder::segtree<S, op, e>;

int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    // j, i
    vector<pair<ll, ll>> coins(n);
    for (ll i = 0; i < n; ++i) {
        ll r, c;
        cin >> r >> c;
        --r;
        --c;
        coins[i] = { c, r };
    }
    ranges::sort(coins, greater<>());

    vector<ll> next(n, -1);
    SegTree seg(h);
    for (ll ci = 0; ci < n; ++ci) {
        auto [j, i] = coins[ci];
        auto [value, index] = seg.prod(i, h);
        next[ci] = index;
        seg.set(i, { value + 1, ci });
    }

    auto [ans, ci] = seg.all_prod();
    cout << ans << endl;
    string route;
    route.reserve(h+w);
    ll r = 0;
    ll c = 0;
    while (ci != -1) {
        auto [c2, r2] = coins[ci];
        for (; r < r2; ++r) {
            route += 'D';
        }
        for (; c < c2; ++c) {
            route += 'R';
        }
        ci = next[ci];
    }
    for (; r < h-1; ++r) {
        route += 'D';
    }
    for (; c < w-1; ++c) {
        route += 'R';
    }
    cout << route << endl;

    return 0;
}