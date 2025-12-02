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
    // (r, l)
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; ++i) {
        ll x, l;
        cin >> x >> l;
        a[i] = {x+l, x-l};
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    ll left = -INF;
    for (const auto &[r, l] : a) {
        if (l >= left) {
            ++ans;
            left = r;
        }
    }
    cout << ans << endl;

    return 0;
}