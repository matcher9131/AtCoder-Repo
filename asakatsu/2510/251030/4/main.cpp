#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
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
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    atcoder::dsu g(2e5);
    for (ll i = 0; i < n/2; ++i) {
        g.merge(a[i], a[n-1-i]);
    }

    auto groups = g.groups();
    ll ans = 0;
    for (const auto &group : groups) {
        ans += (ll)group.size() - 1;
    }
    cout << ans << endl;

    return 0;
}