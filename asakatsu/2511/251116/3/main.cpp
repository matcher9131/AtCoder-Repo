#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

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
using LazySegTree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

int main() {
    ll n;
    cin >> n;
    LazySegTree a(n);
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        a.set(i, ai);
    }

    priority_queue<ll, vector<ll>, greater<ll>> que;
    for (ll i = 0; i < n; ++i) {
        a.apply(0, i, -1);
        ll newVal = a.get(i) + (ll)que.size();
        a.set(i, newVal);
        que.push(i + newVal);
        while (!que.empty() && que.top() <= i) que.pop();
    }

    for (ll i = 0; i < n; ++i) {
        ll ai = a.get(i);
        cout << (ai < 0 ? 0 : ai) << " \n"[i == n - 1];
    }

    return 0;
}