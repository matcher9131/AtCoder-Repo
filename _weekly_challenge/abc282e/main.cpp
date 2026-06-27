#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/math>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // val, i, j
    vector<tuple<ll, ll, ll>> e;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i+1; j < n; ++j) {
            ll val = (atcoder::pow_mod(a[i], a[j], m) + atcoder::pow_mod(a[j], a[i], m)) % m;
            e.emplace_back(val, i, j);
        }
    }
    sort(e.begin(), e.end(), greater<>());

    atcoder::dsu d(n);
    ll selected = 0;
    ll ans = 0;
    for (const auto &[val, i, j] : e) {
        if (selected == n-1) break;
        if (!d.same(i, j)) {
            ans += val;
            d.merge(i, j);
            ++selected;
        }
    }
    cout << ans << endl;

    return 0;
}