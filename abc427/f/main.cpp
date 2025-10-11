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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<unordered_map<ll, ll>> fMap(2);
    auto dfs = [&](auto f, ll last, ll cur) -> void {
        ++fMap[last == n/2-1][cur%m];
        for (ll i = last + 2; i < n/2; ++i) {
            f(f, i, cur + a[i]);
        }
    };
    dfs(dfs, -2, 0);

    vector<unordered_map<ll, ll>> lMap(2);
    auto dfs2 = [&](auto f, ll last, ll cur, bool containsFirst) -> void {
        ++lMap[containsFirst][cur%m];
        for (ll i = last + 2; i < n; ++i) {
            f(f, i, cur + a[i], containsFirst || (i == n/2));
        }
    };
    dfs2(dfs2, n/2-2, 0, false);

    ll ans = 0;
    for (const auto &[r, c] : fMap[0]) {
        ll rr = r == 0 ? 0 : m-r;
        ans += c * (lMap[0][rr] + lMap[1][rr]);
    }
    for (const auto &[r, c] : fMap[1]) {
        ll rr = r == 0 ? 0 : m-r;
        ans += c * lMap[0][rr];
    }

    cout << ans << endl;

    return 0;
}