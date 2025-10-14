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
    unordered_map<ll, ll> m;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        ++m[ai];
    }

    ll ans = 0;
    for (const auto &[v, c] : m) {
        if (c >= v) ans += c - v;
        else ans += c;
    }
    cout << ans << endl;


    return 0;
}