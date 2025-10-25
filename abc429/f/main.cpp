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

using S = vector<vector<ll>>;
S op(S a, S b) {
    if (a.empty()) return b;
    if (b.empty()) return a;

    vector<vector<ll>> c(3, vector<ll>(3, INF));
    for (ll i = 0; i < 3; ++i) {
        for (ll j = 0; j < 3; ++j) {
            for (ll k = 0; k < 3; ++k) {
                chmin(c[i][j], a[i][k] + b[k][j]);
            }
        }
    }

    return c;
}
S e() {
    return vector<vector<ll>>();
}

int main() {
    ll n;
    cin >> n;
    atcoder::segtree<S, op, e> seg(n);
    auto segSet = [&](ll k, ll bit) -> void {
        vector<vector<ll>> d(3, vector<ll>(3));
        for (ll i = 0; i < 3; ++i) {
            for (ll j = 0; j < 3; ++j) {
                if ((bit & (1LL << i)) || (bit & (1LL << j))) d[i][j] = INF;
                else d[i][j] = abs(j - i);
            }
        }
        if (bit == 2) {
            d[0][2] = d[2][0] = INF;
        }
        seg.set(k, d);
    };

    vector<string> s(3);
    for (ll i = 0; i < 3; ++i) {
        cin >> s[i];
    }
    vector<ll> pattern(n);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 3; ++j) {
            if (s[j][i] == '#') pattern[i] |= 1LL << j;
        }
        segSet(i, pattern[i]);
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll r, c;
        cin >> r >> c;
        --r;
        --c;
        pattern[c] ^= 1LL << r;
        segSet(c, pattern[c]);
        ll ans = seg.all_prod()[0][2];
        cout << (ans == INF ? -1 : ans + n-1) << "\n";
    }

    return 0;
}