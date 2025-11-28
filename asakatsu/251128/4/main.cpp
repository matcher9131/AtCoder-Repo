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
    map<ll, ll> m;
    for (ll i = 0; i < n; ++i) {
        ll s, c;
        cin >> s >> c;
        m[s] += c;
    }

    for (auto it = m.begin(); it != m.end(); ++it) {
        auto [s, c] = *it;
        it->second = c%2;
        m[it->first * 2] += c/2;
    }

    ll ans = 0;
    for (const auto &[s, c] : m) {
        ans += c;
    }
    cout << ans << endl;

    return 0;
}