#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll xs = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        xs ^= a[i];
    }

    auto dfs = [&](auto f, ull state, ll cur) -> ll {
        if (cur == 0) return -1;
        ll res = -INF;
        for (ll i = 0; i < n; ++i) {
            if (state & (1ULL << i)) continue;
            chmax(res, -f(f, state | (1ULL << i), cur ^ a[i]));
        }
        return res;
    };
    cout << (dfs(dfs, 0, xs) ? "Win" : "Lose") << endl;

    return 0;
}