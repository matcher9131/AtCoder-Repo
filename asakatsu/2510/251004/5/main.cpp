#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
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
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        auto [_, j] = a[i];
        if (i%2 != j%2) ++ans;
    }
    cout << ans/2 << endl;

    return 0;
}